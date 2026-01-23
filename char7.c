#include <stdio.h>

#define SIZE 2

int main() {
  char b[SIZE] = {
    '\0',
    'a'
  };

  for (char i = 0; i < SIZE; i++) {
    if (b[i] == '\0') printf("null term\n");
    else 
    printf("%c\n", b[i]);
  }
}
