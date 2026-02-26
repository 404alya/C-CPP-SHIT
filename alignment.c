#include <stdio.h>

typedef struct
{
    short s;
    int i;
    char c;
} test1;

typedef struct  
{
    int i;
    char c;
    short s;
} test2;

int main()
{
    test1 t1;
    test2 t2;
   
    printf("test1: %lu\n", sizeof(test1));
    printf("test2: %lu\n", sizeof(test2));


    return 0;
}
