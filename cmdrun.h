#include <stdlib.h>
#include <unistd.h>

typedef int Nob_Proc;
#define NOB_INVALID_PROC (-1)
typedef int Nob_Fd;
#define NOB_INVALID_FD (-1)

#ifndef NOBDEF
/*
   Goes before declarations and definitions of the nob functions. Useful to `#define NOBDEF static inline`
   if your source code is a single file and you want the compiler to remove unused functions.
*/
#define NOBDEF
#endif /* NOBDEF */

typedef struct {
    Nob_Proc *items;
    size_t count;
    size_t capacity;
} Nob_Procs;

// A command - the main workhorse of Nob. Nob is all about building commands and running them
typedef struct {
    const char **items;
    size_t count;
    size_t capacity;
} Nob_Cmd;

// Options for nob_cmd_run_opt() function.
typedef struct {
    // Run the command asynchronously appending its Nob_Proc to the provided Nob_Procs array
    Nob_Procs *async;
    // Maximum processes allowed in the .async list. Zero implies nob_nprocs().
    size_t max_procs;
    // Do not reset the command after execution.
    bool dont_reset;
    // Redirect stdin to file
    const char *stdin_path;
    // Redirect stdout to file
    const char *stdout_path;
    // Redirect stderr to file
    const char *stderr_path;
} Nob_Cmd_Opt;


NOBDEF int nob_nprocs(void)
{
#ifdef _WIN32
    SYSTEM_INFO siSysInfo;
    GetSystemInfo(&siSysInfo);
    return siSysInfo.dwNumberOfProcessors;
#else
    return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}


static int nob__proc_wait_async(Nob_Proc proc, int ms)
{
  if (proc == NOB_INVALID_PROC) return false;

  long ns = ms*1000*1000;
  struct timespec duration = {
      .tv_sec = ns/(1000*1000*1000),
      .tv_nsec = ns%(1000*1000*1000),
  };

  int wstatus = 0;
  pid_t pid = waitpid(proc, &wstatus, WNOHANG);
  if (pid < 0) {
      nob_log(NOB_ERROR, "could not wait on command (pid %d): %s", proc, strerror(errno));
      return -1;
  }

  if (pid == 0) {
      nanosleep(&duration, NULL);
      return 0;
  }

  if (WIFEXITED(wstatus)) {
      int exit_status = WEXITSTATUS(wstatus);
      if (exit_status != 0) {
          nob_log(NOB_ERROR, "command exited with exit code %d", exit_status);
          return -1;
      }

      return 1;
  }

  if (WIFSIGNALED(wstatus)) {
      nob_log(NOB_ERROR, "command process was terminated by signal %d", WTERMSIG(wstatus));
      return -1;
  }

  nanosleep(&duration, NULL);
  return 0;
}



NOBDEF bool nob_cmd_run_opt(Nob_Cmd *cmd, Nob_Cmd_Opt opt)
{
    bool result = true;
    Nob_Fd fdin  = NOB_INVALID_FD;
    Nob_Fd fdout = NOB_INVALID_FD;
    Nob_Fd fderr = NOB_INVALID_FD;
    Nob_Fd *opt_fdin  = NULL;
    Nob_Fd *opt_fdout = NULL;
    Nob_Fd *opt_fderr = NULL;
    Nob_Proc proc = NOB_INVALID_PROC;

    size_t max_procs = opt.max_procs > 0 ? opt.max_procs : (size_t) nob_nprocs() + 1;

    if (opt.async && max_procs > 0) {
        while (opt.async->count >= max_procs) {
            for (size_t i = 0; i < opt.async->count; ++i) {
                int ret = nob__proc_wait_async(opt.async->items[i], 1);
                if (ret < 0) nob_return_defer(false);
                if (ret) {
                    nob_da_remove_unordered(opt.async, i);
                    break;
                }
            }
        }
    }

    if (opt.stdin_path) {
        fdin = nob_fd_open_for_read(opt.stdin_path);
        if (fdin == NOB_INVALID_FD) nob_return_defer(false);
        opt_fdin = &fdin;
    }
    if (opt.stdout_path) {
        fdout = nob_fd_open_for_write(opt.stdout_path);
        if (fdout == NOB_INVALID_FD) nob_return_defer(false);
        opt_fdout = &fdout;
    }
    if (opt.stderr_path) {
        fderr = nob_fd_open_for_write(opt.stderr_path);
        if (fderr == NOB_INVALID_FD) nob_return_defer(false);
        opt_fderr = &fderr;
    }
    proc = nob__cmd_start_process(*cmd, opt_fdin, opt_fdout, opt_fderr);

    if (opt.async) {
        if (proc == NOB_INVALID_PROC) nob_return_defer(false);
        nob_da_append(opt.async, proc);
    } else {
        if (!nob_proc_wait(proc)) nob_return_defer(false);
    }

  defer:
      if (opt_fdin)  nob_fd_close(*opt_fdin);
      if (opt_fdout) nob_fd_close(*opt_fdout);
      if (opt_fderr) nob_fd_close(*opt_fderr);
      if (!opt.dont_reset) cmd->count = 0;
      return result;
}

