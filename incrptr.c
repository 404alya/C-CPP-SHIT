#include <stdio.h>

void incr(int *a) {
  printf("B: %d \n", *a);
  *a++;
  printf("A: %d \n", *a);
}

int main() {
  int a = 1;

  incr(&a);

  printf("%d", a);
}
