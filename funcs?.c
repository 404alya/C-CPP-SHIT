#include <stdio.h>

void callback(void (*func)(char*,double)) {
  func("%f", 1.0);
}

double cos_taylor_literal_4terms_naive(double x)
{
    return 1 - ((x * x) / (2)) + ((x * x * x * x) / (24)) - ((x * x * x * x * x * x) / (720)) + ((x * x * x * x * x * x * x * x) / (40320));
}

#define RTEST(x)  { #x, x }

static struct {
    char name[35];
    double (*func)(double v);
} tests[] = {
    /* cos_taylor_literal */
    RTEST(cos_taylor_literal_4terms_naive)
  };

#define TEST(x) #x


int main() {
  printf("%f\n", tests[0].func(1.0));
  return 0;
}
