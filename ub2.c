#include <stdio.h>

double absd(double a) { *((unsigned long *)&a) &= ~(1UL << 63); return a; }

int main() {
  unsigned long a = 0.0;
  for (double a = -200; a < 200; a++) {
      printf("%f\n", absd(a));
  }
}
