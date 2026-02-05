#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// https://en.wikipedia.org/wiki/Bitwise_operations_in_C

void showbits( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

int wikipediaExamp()
{
    putchar('a');
    int j = 5225;
    printf("%d in binary ", j);
    showbits(j);

    /* the loop for right shift operation */
    for (int m = 0; m <= 5; m++)
    {
        int n = j >> m;
        printf("%d right shift %d gives ", j, m);
        showbits(n);
    }
    return 0;
}

// https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp

#define print_bits(x)                                            \
  do {                                                           \
    unsigned long long a__ = (x);                                \
    size_t bits__ = sizeof(x) * 8;                               \
    while (bits__--) {                                           \
      putchar(a__ &(1ULL << bits__) ? '1' : '0');                \
    }                                                            \
    putchar('\n');                                               \
  } while (0)                                                    \

// Don't do this because -> https://stackoverflow.com/questions/2687569/c-do-while0?noredirect=1&lq=1
#define SAFE_FREE(x) if ((x) != NULL) { free(x); x=NULL; }


#define urmom(x)   {       \
    printf("test1234");    \
    printf("adsa");        \
  }                        \
 
int geeksForGeeks() {
    // a = 21(00010101)
    unsigned char a = 21;

    // The result is 00101010
    printf("a << 1 = %d\n", (a << 2));
  
  	// The result is 00000101
  	printf("a >> 2 = %d", (a >> 2));

    return 0;
}

int main() {
 // wikipediaExamp();
  int* a = NULL;

 if (1) SAFE_FREE(a)
  else { printf("\nG3232\n"); }


  printf("%d", 2 << 3);
 

  unsigned long long pong = 2;
  printf("urmom@mypong %llu", pong);

  printf("\n bits:");
  printf("\n a:");
  print_bits(69);

  printf("\n b:");
  print_bits(1);
  
  for (int a = 0; a < 9; a++) {
    printf("\n a: %d index\n", a);
    print_bits(1ULL << a);
    print_bits(a << 1ULL);
  }

  printf("\n d:");
  print_bits(1ULL);

  printf("\n c:");
  print_bits(0);
  printf("\n");
  showbits(1);

  if (1) {
    urmom(2);
    printf("urmom 1");
  } else printf("urmom 2");


  printf("\n urdad: %d",  69 & 1);

  printf("\n urgrandmother %d", ~10);


  /* 
   *
   *ya simdi
64 bit unsigned long longumuz var
ben simdi bunu
surekli saga itersem bitwise operation ile
1ULL << bit_amount 
ve
bu bit amount her iterationda azalirsa
ve eger her iterationda, target degeri ile 1ULL << bit_amount arasinda bir bitwise and calculation yapip eger bunun sonucu 0 degil ise buffera "1" eger oyle ise "0" eklersem
target degerinin binary representationini mi aliyorum
evet
NIYE KAFAM ALMIYO BUNU 2 SAASTTIR
anlayamiyorum
belki anlamaya calismaman gerekiyordur belki cok salaksindir
sus
yani neden alihyorumki
bi dk
Tamam bu targetin binarysini almak icin kullandigimiz looptaki degerlerden biri:

0000000000000000000000000000000000000000000000000000000000000001
simdi
bu ne demek?
1 demek
cunku en saginda 1 var
tamam
69 & 1
kac yapar
once 69 un binarysi lazm
dogru dur
69 binarysi bu:

 00000000000000000000000001000101
bunu 64 bite cevirirsek
0000000000000000000000000000000000000000000000000000000001000101
tamamdir
simdi
0000000000000000000000000000000000000000000000000000000000000001
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000000000001
yani 69 & 1 = 1
evet 1 mis
tamam
o zaman
404

 — 6:38 PM
basina 1 ekliyoruz?
0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 0 \ 1. \ 0. \ 0. \ 0. \ 1. \ 0. \ 1.


🔴 
tamamdir
simdi
bunu sabitleyelim dur
tamam simdi
diger sayimiz
yani her seferinde sagina 0 geliyo sola kayiyo
0000000000000000000000000000000000000000000000000000000000000010
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000000000000
yani bu 0 oluyo
dur bunu kac kere yapmak lazim hm
32 defa
integerlar 32 bit cunku
okay I still don't get it
sakin oll
tamam
404

 — 6:46 PM
0000000000000000000000000000000000000000000000000000000000000100
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000000000100
hm bu kac ytapiyo
4 sanirsam
bakaym
4mus evet
4 pozitif
o zamn 1
0000000000000000000000000000000000000000000000000000000000001000
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000010000
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000000100000
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000000000000
0000000000000000000000000000000000000000000000000000000001000000
+
0000000000000000000000000000000000000000000000000000000001000101
=
0000000000000000000000000000000000000000000000000000000001000000
64 yapiyo
1
amina koyim
cidden
aynisi cikti
HALA ANLAMIYOM
mantiki olarak dogru calisiyor evet
AMA NEDN
bilmiyorum
belki this is the one of the thing that I shouldn't try to understand right?
zaten kim ikili sistem seklinde dusunebiliyor
fucking 10 parmagim var o yuzden 10 lu dusunuyom anlamiyom
kafam yandi
anlicam sikjerler
aaaaaaaaaaaaaaaaaaaa
ANLADIM
tamam
404

 — 6:53 PM
tamamdir
tamam
TAMAMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMM
FOR (INT M = 0; M < 300; M++) {
  putchar('M');
} 
OKAY....
but still don't know the tilda shit that was the reason why I started to understand this shit, I should learn it
   *
   * */
  return 0;
}
