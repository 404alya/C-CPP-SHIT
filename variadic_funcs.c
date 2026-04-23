#include <stdarg.h>
#include <stdio.h>

int getSum(void *n, ...) {
  int sum = 0;
  va_list list;
  
  va_start(list, n);

  sum += va_arg(list, int);

  va_end(list);

  return sum;
}

int main() { printf("%d\n", getSum(NULL, 1, 4)); }
