#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * a;

int fib(int i) {
  printf("iter %d value %d\n", i, a[i]);

  if (i == 0) {
    a[0] = 0;
    return a[0];
  }

  if (i == 1) {
    a[1] = 1;
    return a[1];
  }

  if (!(a[i] > 0)) {
    int c = fib(i - 1);
    int b = fib(i - 2);
    a[i] = c + b;
  }

  return a[i];
}

int main() {
  int fib_num = 22;
  a = calloc(fib_num + 1, sizeof(int));
  fib(fib_num);
}
