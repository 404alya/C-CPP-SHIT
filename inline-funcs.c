#include <stdio.h>

 extern inline int sum(int a, int b) {
  return a + b;
}

int main() {
  int total =  sum(1, 2);
  printf("%d", total);
  
  return 0;
}
