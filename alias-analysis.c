/*
https://www.kdab.com/understanding-type-based-alias-analysis-in-c-and-cpp/
Assuming the function call is modifyValues(&n, (short*)&n) here, n might be an integer type.
What would be the resulting value of n?
It depends on the optimization level. Let’s look at the assembly in the case of no optimization level (O0) and its being compiled with clang.
*/

#include <stdio.h>

void modifyValues(int *a, short *b) {
  *a = 42;
  *b = 3;
  *a += 5;
}


int main() {
  int n;
  modifyValues(&n, (short*)&n);
  printf("%d", n);
  return 0;
}
