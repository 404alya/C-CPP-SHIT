#include <stdio.h>

typedef enum  {
  WIN,
  LINUX,
} Target;

int main() {
  Target target = WIN;

  if (target != -1) {
    printf("aaa");
  }

  return 0;
}
