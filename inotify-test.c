
// Source - https://stackoverflow.com/a/79891557
// Posted by 0___________, modified by community. See post 'Timeline' for change history
// Retrieved 2026-02-18, License - CC BY-SA 4.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

size_t hdr = offsetof(struct inotify_event, name);

int main(void) 
{
  int length, i = 0;
  int fd;
  int wd;
  char buffer[BUF_LEN];

  fd = inotify_init();

  if ( fd < 0 ) {
    perror( "inotify_init" );
  }

  wd = inotify_add_watch( fd, "/home/pc404/Projects/c-cpp-shit", 
                         IN_MODIFY | IN_CREATE | IN_DELETE );
  
  length = read( fd, buffer, BUF_LEN );  

  if ( length < 0 ) {
    perror( "read" );
  }  

  while ( i < length ) {
    struct inotify_event event;
    memcpy(&event,&buffer[ i ], sizeof(event));
    char *name = &buffer[ i + hdr];
    if ( event.len ) {
      if ( event.mask & IN_CREATE ) {
        if ( event.mask & IN_ISDIR ) {
          printf( "The directory %s was created.\n", name );       
        }
        else {
          printf( "The file %s was created.\n", name );
        }
      }
      else if ( event.mask & IN_DELETE ) {
        if ( event.mask & IN_ISDIR ) {
          printf( "The directory %s was deleted.\n", name );       
        }
        else {
          printf( "The file %s was deleted.\n", name );
        }
      }
      else if ( event.mask & IN_MODIFY ) {
        if ( event.mask & IN_ISDIR ) {
          printf( "The directory %s was modified.\n", name );
        }
        else {
          printf( "The file %s was modified.\n", name );
        }
      }
    }
    i += EVENT_SIZE + event.len;
  }

  ( void ) inotify_rm_watch( fd, wd );
  ( void ) close( fd );

  exit( 0 );
}
