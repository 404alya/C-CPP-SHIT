#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void eprintf(const char *format, int n, ...) {
  va_list list;
  va_start(list, n);

  int args[n] = {};

  for (int i = 0; i < n; i++)
    args[i] = va_arg(list, int);

  char *pcBuf;

  pcBuf = malloc((n * sizeof(int)) + n + 1);

  for (short i = 0; i < n; ++i)
    sprintf(pcBuf, "%d ", args[i]);

  printf("%s \n", pcBuf);
}
__attribute__((format(printf, 1, 2))); /* 1=format 2=params */

/* like printf() but to standard error only */

int main(int argc __attribute__((unused)),
         char **argv __attribute__((unused))) {
  eprintf("hey", 2, 2);
}
