#include <stdio.h>
#include <string.h>

#define SHIFT(x, y) (((x) + (y * SNAKE_GAME_WIDTH)) * SNAKE_CELL_MAX_BITS)
#define SNAKE_GAME_WIDTH 24U
#define SNAKE_CELL_MAX_BITS 3U /* floor(log2(SNAKE_CELL_FOOD)) + 1 */

int main() { 

   char cr[3] = { 'a', 'b' };
   int ar[3] = { 1, 2 };

   printf("character array output using printf() : ");
   printf(cr);

   printf("\n\nInteger array output using printf() : ");
   printf(ar);
   printf("\n");

   return 0;
  
}
