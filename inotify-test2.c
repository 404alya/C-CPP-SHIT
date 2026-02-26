#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define EVENT_SIZE sizeof(struct inotify_event) 
#define ALLOCATED_EVENT_SIZE EVENT_SIZE + NAME_MAX + 16
#define BUF_LEN (1 * (ALLOCATED_EVENT_SIZE))


int main() {
  char buf[BUF_LEN];
  int inotify_fd, wd, i, byte_read;
  char* pathname = "./note.txt";
  struct inotify_event event;

  while (1) {
    inotify_fd = inotify_init();
    wd = inotify_add_watch(inotify_fd, pathname, IN_MODIFY | IN_ATTRIB);
    byte_read = read(inotify_fd, buf, BUF_LEN);
    i = 0;
   
    while (i < byte_read) {
      memcpy(&event, &buf[i], EVENT_SIZE);
      uint32_t mask = event.mask;
      if (mask & IN_ATTRIB || mask & IN_MODIFY) {
          printf("File has been modified\n");
      }
    
      i += ALLOCATED_EVENT_SIZE;
    }

    ( void ) inotify_rm_watch( inotify_fd, wd );
    ( void ) close( inotify_fd );
  }
  return 0;
}
