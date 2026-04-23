#include <stdio.h>

typedef struct {
    void     (*sa_handler)(int);
    int        sa_flags;
    void     (*sa_restorer)(void);
} sigaction;

void test(int a) {
  printf("this is from test! %d", a);
};

int main() {
  sigaction a = {
    .sa_handler = test
  };

  a.sa_handler(20);
  return 0;
}
