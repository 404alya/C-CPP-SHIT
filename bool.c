#include <stdio.h>
#include <uchar.h>
#include <stdbool.h>

#define print_bits(x)                                       \
  do {                                                           \
    typeof(x) a__ = (x);                                              \
    unsigned int bits__ = sizeof(x) * 8;                               \
    while (bits__--) {                                           \
      putchar(a__ &(1ULL << bits__) ? '1' : '0');                \
    }                                                            \
    putchar('\n');                                               \
  } while (0)                                                    \

// 1 byte value (on a system where 8 bits is a byte)
typedef struct
{
      int   p3:1;   // 1 bit
} SomeThg;

struct test {

      char   p3:1;   // 1 bit
};

int main() {
  bool a = false;
  SomeThg b = {0};
  
  SomeThg *p1 = &b;

  printf("sizeof struct %lu\n", sizeof(b));
  p1->p3 = -1;
  printf("URMOM: %d\n", p1->p3);
  printf("URMOM: %lu\n", sizeof(struct test));

  bool u = true;
  print_bits(u);

  return 0;
}
