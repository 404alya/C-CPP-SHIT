#include <stdio.h>

int main() {
  int i = 0;
  double d = 3.14;
  i = static_cast<decltype(i)>(d);
}
