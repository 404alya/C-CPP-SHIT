#include <pthread.h>
#include <stdio.h>

volatile int num = 1;

void* foo() {
  while (1) {
    num++;
 //   printf("num1: %d\n", num);
  }
  return NULL;
}

int main() {
  pthread_t thread1;
  pthread_create(&thread1, NULL, foo, NULL);

  while (1) {
    printf("num2: %d\n", num);
  }


  pthread_join(thread1, NULL);
  return 0;
}
