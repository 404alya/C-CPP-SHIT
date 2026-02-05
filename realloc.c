#include <stdio.h>
#include <stdlib.h>

int main() {
  int *dArray = malloc(sizeof(int) * 30);
  int count = 0;

  while (1) {
    int input;
    printf("Please enter input:\n");
    scanf("%d", &input);

    printf("Enter the capacity to reallocate memory:\n");
    
    int mem;
    scanf("%d", &mem);
    
    dArray = realloc(dArray, sizeof(int) * mem);

    dArray[count] = input;
    printf("entered input %d \n", input);
    count++;

      
    for (int i = 0; i < count; i++) {
      printf("value %d: %d\n", i, dArray[i]);
    }
  }

  return 0;
}
