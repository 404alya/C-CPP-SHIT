#include <stdio.h>

void test(float *a) {
  a[0] = 0;
}

int main() {
  test();
  return 0;
}
