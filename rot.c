#include <stdio.h>
#include <math.h>

// Vector3, 3 components
typedef struct Vector3 {
    float x;                // Vector x component
    float y;                // Vector y component
    float z;                // Vector z component
} Vector3;

int main() {
  
  for (int rot = 0; rot < 50; ++rot) {
    Vector3 front = (Vector3){ sinf(rot), 0.f, cosf(rot) };
    Vector3 right = (Vector3){ cosf(-rot), 0.f, sinf(-rot) };
    
    printf("front = %f %f %f\n", front.x, front.y, front.z);
    printf("rightt = %f %f %f\n", right.x, right.y, right.z);
  }

  return 0;
}
