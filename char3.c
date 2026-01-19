#include <stdio.h>
#include <string.h>

int main() {
  char ca[20] = { 0, 3, 4, 6, 7, 2, 4, 2, 4};
  unsigned short range;

  memcpy(&range, ca+1, sizeof(range));

  ca++;

  

  printf("%d", range);
}
