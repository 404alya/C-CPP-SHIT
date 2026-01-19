#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  char string[] = "bla2321";

  int sum = 0;

  printf("%d\n", true);

  for (int i = 0; i < strlen(string); i++) {
    if (isdigit(string[i])) {
      sum += string[i] - '0';
    }
  }

  printf("sum: %d \n", sum);

  return 0;
}
