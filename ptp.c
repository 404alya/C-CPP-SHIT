#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *p = malloc(2);
  char **ptp = &p;
  char ***ptp2 = &ptp;

  printf("%s", ptp);
  return 0;
}
