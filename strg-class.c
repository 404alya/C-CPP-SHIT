#include <stdio.h>

void counter() {
  static int count = 0;
  count++;
  printf("Count: %d\n", count);
}

void counter2() {
  auto int count = 0;
  count++;
  printf("Count2: %d\n", count);
}

void counter3() {
  register int count = 0;
  count++;
  printf("Count3: %d\n", count);
}

void counter4() {
  static int count = 0;
  count++;
  printf("Count4: %d\n", count);
}

extern int count = 0;

void counter5() {
  count++;
  printf("Count5: %d\n", count);
}

int main() {
  counter();
  counter();

  counter2();
  counter2();

  counter3();
  counter3();
 
  counter4();
  counter4();
  return 0;
}
