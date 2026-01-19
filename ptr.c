// https://stackoverflow.com/questions/18481740/pointer-expressions-ptr-ptr-and-ptr

#include <stdio.h>

int main() {
  char *p = "Hello";
  printf("1: %c\n", p[0]);
  while(*p) {
      printf("%c",*++p);
  }


  char q[] = "Hello";
  char* o = q;
  printf ("\n%c", (*o)++);
  printf ("%c\n", *o);


  return 0;
}
