#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int x = 0;

void* foo() {
  for (int i = 0; i < 100000000; i++) {
    x++;
  }

  return NULL;
}

int main(int argc, char* argv[]) {
  pthread_t p1, p2;
  pthread_create(&p1, NULL, &foo, NULL);
  pthread_create(&p2, NULL, &foo, NULL);
  

  pthread_join(p2, NULL);
  pthread_join(p1, NULL);

  printf("x: %d", x);

  return 0;
}
