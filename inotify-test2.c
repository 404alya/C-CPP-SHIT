#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EVENT_SIZE sizeof(struct inotify_event) 
#define ALLOCATED_EVENT_SIZE EVENT_SIZE + NAME_MAX + 1
#define EVENT_COUNT_PER_ITERATION 10
#define BUF_LEN (EVENT_COUNT_PER_ITERATION * (ALLOCATED_EVENT_SIZE))

int main() {
  char buf[BUF_LEN];
  int inotify_fd, wd, eCount, irmw, closedFd;
  size_t byte_read, i;
  char fileExists = 1;
  char* pathname = "./note.txt";
  struct inotify_event event;

  while (1) {
    inotify_fd = inotify_init();
    if (inotify_fd < 0) {
      perror( "inotify_init" );
      exit(EXIT_FAILURE);
    }

    wd = inotify_add_watch(inotify_fd, pathname, IN_MODIFY | IN_ATTRIB);
    if (wd < 0) {
      perror("inotify_add_watch");
      exit(EXIT_FAILURE);
    }

    byte_read = read(inotify_fd, buf, BUF_LEN);
    if (byte_read < 0) {
      perror( "byte_read" );
      exit(EXIT_FAILURE);
    }

    if (byte_read == 0) continue;
    

    i = 0;
    eCount = 0;
    fileExists = 1;

    while (i < byte_read) {
      memcpy(&event, &buf[i], EVENT_SIZE);
      uint32_t mask = event.mask;
 
      printf("TYPE: ");
      if (mask & IN_ISDIR) printf("[DIRECTORY]\n");
      else printf("[FILE]\n");
      
      if (mask & IN_MODIFY) printf(" has been modified\n");
      if (mask & IN_ATTRIB) printf(" metadata has been changed\n");
      if (mask & IN_IGNORED || mask & IN_UNMOUNT || mask & IN_DELETE_SELF) fileExists = 0;

      eCount++;
      if (eCount == EVENT_COUNT_PER_ITERATION) break;
      i += EVENT_SIZE + event.len;
    }
 
    if (fileExists) {
      irmw = inotify_rm_watch( inotify_fd, wd );
      if (irmw < 0) {
        perror( "inotify_rm_watch" );
        exit(EXIT_FAILURE);
      }
    }

    closedFd = close( inotify_fd );
    if (closedFd < 0) {
      perror( "fd close" );
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
