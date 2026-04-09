
#include <stdio.h>
#include <stdlib.h>

#define PATH_MAX 90

int main() {
  FILE *fp;
  int status;
  char path[PATH_MAX];

  fp = popen("ls -a", "r");
  if (fp == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
  }

  status = pclose(fp);
  if (status == -1) {
    perror("pclose");
    exit(EXIT_FAILURE);
  } else {
      /* Use macros described under wait() to inspect `status' in order
        to determine success/failure of command executed by popen() */
  }
  return 0;
}
