#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/inotify.h>

int main() {
  char buff[50];
  int fd = inotify_init();

  int wd = inotify_add_watch(fd, "/home/pc404/Projects/c-cpp-shit", IN_MODIFY);

  read(fd, buff, sizeof(buff));
  

  printf("%s", buff);
}
