#include <stdio.h>
#include <sys/time.h>

int main(void)
{
  struct timeval t1, t2;
  double elapsedTime;

  // Start timer
  gettimeofday(&t1, NULL);

  // Do something
  // ...

  // Stop timer
  gettimeofday(&t2, NULL);

  // Compute and print the elapsed time in milliseconds:

  // Seconds to milliseconds
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;

  // Microseconds to milliseconds
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

  printf("%f ms.\n", elapsedTime);
}
