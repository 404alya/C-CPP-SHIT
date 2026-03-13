#include <stdio.h>


int main() {
  for (float hi = 0.0; hi < 1.0; hi += 0.005) {
    printf("%f: %f %f\n",  hi, (1.0 - hi),  (1.0 - hi) * hi);
  }


  return 0;
}
