#include <stdio.h>

typedef struct {
  int a;
  int b;
  int c;
} ABC;

int main() {
 char buff[10];

  for (int i = 0; i < 10; ++i) {
    ABC *u = (ABC*) &buff[i]; 
    printf("a: %d\n ", u->a);
  }
}
