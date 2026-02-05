#include <stdio.h>

#define CS_HREDRAW 1
#define CS_VREDRAW 2
#define CS_ANOTHERSTYLE 4

unsigned int style = CS_HREDRAW | CS_VREDRAW;

int main() {
  if(style & CS_HREDRAW) printf("1\n");
  if(style & CS_VREDRAW) printf("2\n");
  if(style & CS_ANOTHERSTYLE) printf("3\n");

  return 0;
}
