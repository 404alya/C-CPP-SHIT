#include <stdio.h>
 
void printhexchars(char str[])
{
  printf("U: %d\n", *(str++));
   while(*str)
   {
      printf("%03d ", *(str++));
   }
   /* print last character after while loop: '\0' */
   printf("%03d ", *str);
}
 
int main()
{
   char cr[3] = { 'a', 'b' };
   int ar[3] = { 1, 2 };
  
   printf("character array output using printf() : ");
   printhexchars(cr);
 
   printf("\n\nInteger array output using printf() : ");
   printhexchars(ar);
   printf("\n");
 
   return 0;
}
 
