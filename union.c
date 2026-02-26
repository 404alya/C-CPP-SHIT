#include <stdio.h>

typedef union {
  int index;
  char letter;
} myUnion;

int main() {
  myUnion a;
  int *n = &a.index;
  printf("%p\n", n);
  printf("%p\n", &a);
  n->
  printf("%d ", a.index);
  return 0;
}
