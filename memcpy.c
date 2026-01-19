#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Why is this function inside of string header I don't get it
// https://stackoverflow.com/questions/9782126/why-memory-functions-such-as-memset-memchr-are-in-string-h-but-not-in-stdli

typedef struct {
  unsigned char cells[10];
} ctx;

int main() {
  ctx ctx1 = {"1"};

  printf("%s\n", ctx1.cells + 1);

  unsigned short range;
  const short int shift = 2;
  memcpy(&range, ctx1.cells + (shift / 8), sizeof(range));
  // range = ctx1.cells + (shift / 8);

  return 0;
}
