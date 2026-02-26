#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE sizeof(struct inotify_event)
#define BUF_LEN  ((1024) * (EVENT_SIZE + 16))

typedef struct {
  int a;
  int b;
  int c;
} ABC;
int main(int argc, char **argv) {
  int length, i = 0;
  int fd ;
  int wd;
  int a = BUF_LEN;
  char buffer[BUF_LEN];

printf("EVENT_SIZE: %lu\n", EVENT_SIZE);



  printf("buffLen: %lu\n ", sizeof(buffer) / sizeof(char));
  fd = inotify_init();
  if (fd < 0) {
    perror("inotify_init");
    exit(1);
  };

  wd = inotify_add_watch(fd, "./note.txt",  IN_MODIFY);
  if (wd < 0) {
    perror("inotify_add_watch");
    exit(1);
  }

  length = read(fd, buffer, BUF_LEN);

  if (length <= 0) {
    perror("Couldn't read file");
    exit(1);
  }

  printf("length: %d buffer: %s buffLen: %lu\n ", length, buffer, sizeof(buffer) / sizeof(char));
  
  for (int i = 0; i < sizeof(buffer) / sizeof(char); ++i) {
    struct inotify_event *event = (struct inotify_event*) &buffer[i];
    
    printf("event size: %lu\n", EVENT_SIZE);
    printf("event len: %d\n", event->len);
    printf("event watch descriptor: %d \n", event->wd);
    printf("event cookie: %d\n", event->cookie);
    printf("event mask: %d\n", event->mask);
    printf("event name: %s\n", event->name);

    if (event->len) {
      if ( event->mask & IN_CREATE ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "The directory %s was created.\n", event->name );       
        }
        else {
          printf( "The file %s was created.\n", event->name );
        }
      }
      else if ( event->mask & IN_DELETE ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "The directory %s was deleted.\n", event->name );       
        }
        else {
          printf( "The file %s was deleted.\n", event->name );
        }
      }
      else if ( event->mask & IN_MODIFY ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "The directory %s was modified.\n", event->name );
        }
        else {
          printf( "The file %s was modified.\n", event->name );
        }
      }
    }
  }
  return 0;
}
