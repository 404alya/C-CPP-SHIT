#include <math.h>
#include <stdio.h>

int main() {
  double num = -4.72365;

  for (int i = 0; i < 800; ++i) {
    num += 0.5;
    double res;
    res = exp(num);
    printf("e raised to the power %.2lf = %.2lf\n", num, res);
  }

  return 0;
}
