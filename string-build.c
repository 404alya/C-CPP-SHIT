#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void str_append(char **src, const char *fmt, ...) {
  va_list args;
  char *new_part = NULL;

  va_start(args, fmt);
  int n = vasprintf(&new_part, fmt, args); 
  va_end(args);

  if (n == -1) {
    perror("vasprintf str_append");
    exit(EXIT_FAILURE);
  }

  if (n == 0) return;

  if (*src == NULL) *src = malloc(strlen(new_part) + 1);
  else {
    *src = realloc(*src, strlen(*src) + strlen(new_part) + 2);
    strcat(*src, " ");  
  }

  strcat(*src, new_part);

  free(new_part);
}

void cmd_append(char **src, const char *fmt, ...) {
  va_list args;
  char *new_part = NULL;

  va_start(args, fmt);
  int n = vasprintf(&new_part, fmt, args); 
  va_end(args);

  if (n == -1) {
    perror("vasprintf cmd_append");
    exit(EXIT_FAILURE);
  }

  if (n == 0) return;

  if (*src == NULL) *src = malloc(strlen(new_part) + 1);
  else {
    *src = realloc(*src, strlen(*src) + strlen(new_part) + 2);
    strcat(*src, " ");  
  }

  strcat(*src, new_part);
  free(new_part);
}

int main() {
  char *str = NULL;
 
  for (int i = 0; i < 20; i++) {
    
  cmd_append(&str, "rm -rf %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out" , "", "", "", "", "", "");
    cmd_append(&str, "rm -rf %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out" , "", "", "", "", "", "");
    cmd_append(&str, "rm -rf %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out %s/build/out/linux/linux.out" , "", "", "", "", "", "");


  }

  printf("%s\n", str);  
  free(str);
}
