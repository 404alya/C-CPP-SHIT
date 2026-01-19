// Example program to demonstrate sprintf()
#include <stdio.h>
#include <stdlib.h>

#define count 10

int main() {
  // Source - https://stackoverflow.com/a/17467107
  // Posted by Mayur Navadia
  // Retrieved 2026-01-11, License - CC BY-SA 3.0
  char *pcBuf;
  int iLen = 0;
  int array[count] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  pcBuf = malloc((count * sizeof(int)) + count +
                 1); //+count is required for space, and 1 is required for NULL

  for (int i = 0; i < count; ++i)
    iLen += sprintf(pcBuf + iLen, "%d ", array[i]);

  printf("%s \n", pcBuf);
}
