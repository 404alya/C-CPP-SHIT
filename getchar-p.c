// Source - https://stackoverflow.com/q/1391548
// Posted by user158057, modified by community. See post 'Timeline' for change history
// Retrieved 2026-01-22, License - CC BY-SA 3.0

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    char value[4];
      

    printf("1. option 1.\n2. option 2.\n3. option 3.\n4. Exit\n\nMake an option: ");
    fgets(value, n, stdin);
    printf("%d\n", value[0]);

    switch (atoi(&value[0]))
    {
      case 1:
          printf("you selected the option 1.");
          break;
      case 2:
          printf("you selected the option 2.");
          break;
      case 3:
          printf("you selected the option 3.");
          break;
      case 4:
          printf("goodbye");
          break;
      default:
          printf("thats not an option");
          break;
    }

    getchar();
    return 0;
}

