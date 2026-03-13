#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int x = 0;

void* foo() {
  while (1) {
    x++;
    sleep(1);
  }
}

int main(int argc, char* argv[]) {
  pthread_t p1;
  pthread_create(&p1, NULL, &foo, NULL);

  while (1) {
    printf("x: %d\n", x);
    sleep(1);
  }

  pthread_join(p1, NULL);
  return 0;
}
