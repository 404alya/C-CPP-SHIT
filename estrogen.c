#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char counter = 0;

  while (1) {
    if (counter == 127) {
      printf("I give you time to think about it...");
      sleep(10); // sleeps 10 secs
      counter = 0;
    }

    int estrogen;
    printf("Do you taking estrogen?\n");
    scanf("%d", &estrogen);

    int testoteroneBlocker;
    printf("Do you taking testoteroneBlocker?\n");
    scanf("%d", &testoteroneBlocker); 

    printf("a: %d %d", estrogen, testoteroneBlocker);
    if (estrogen && testoteroneBlocker) {
      printf("TODO: implement transfeminie logic");
      exit(EXIT_FAILURE);

      break;
    }

    else if (estrogen && !testoteroneBlocker) {
      printf("wrong choice! think again");
      counter = (counter + 1) % 127;
      continue;
    }
  }
  return 0;
}
