#include <stdarg.h>
#include <stdio.h>

int getSum(int n, ...) {
  int sum = 0;

  va_list list;

  // initilize arguments to list pointer
  va_start(list, n);

  for (int i = 0; i < n; i++)
    sum += va_arg(list, int);

  va_end(list);

  return sum;
}

int main() { printf("%d\n", getSum(2, 2, 2)); }
