#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>
#include <stdlib.h>

char* getAbsolutePath() {
  char* path = malloc(PATH_MAX);
  ssize_t len = readlink("/proc/self/exe", path, PATH_MAX - 1);
  if (len != -1) {
    path[len] = '\0';
    char *last_slash = strrchr(path, '/');
    if (last_slash) *last_slash = '\0';  // truncate at last '/'
  }

  return path;
}



int main() {
  printf("%s", getAbsolutePath());
  return 0;
}
