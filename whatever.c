#include <stdio.h>
#include <math.h>

#define E 2.7182818284
#define H 600.0

int main() {
  float num1 = 2;
  float num2 = H;

  for (int i = 0; i < 200; ++i) {
    num1 += 0.5;
    num2 = H - (pow(E, num1 - 2) + 3);

    printf("1: %f     2: %f\n", num1, num2);
  }
}
