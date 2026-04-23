#include <stdio.h>

int main() {
  int ms = 1500; 
  long ns = ms*1000*1000;
 
  printf("%lu %lu", ns/(1000*1000*1000),  ns%(1000*1000*1000));
 
  return 0;
}
