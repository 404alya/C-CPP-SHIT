#include <math.h>
#include <stdio.h>

float length(float v[3]) {
  return sqrtf(
    (v[0] * v[0]) + 
    (v[1] * v[1]) +
    (v[2] * v[2])
  );
}

int main() {
  float v1[3] = { 10, 3, 0.4 };
  float v2[3] = { 0, 3, 0.4 };
  float radius = 4.0;
  
  float vf[3];
  for (char i = 0; i < 3; i++) {
    vf[i] = v1[i] + v2[i];
  }

  printf("%f", length(vf) - radius);

  return 0;
}
