#include <stdio.h>
#include <math.h>

double f(double x) {
  return x * x - 4;
}

double df(double x) {
  return 2 * x; 
}

double newtonRaphson(double x0, double tolerance, int maxIterations) {
  double x = x0;
  int i;

  for (i = 0; i < maxIterations; i++) {
    double fx = f(x);
    double dfx = df(x);

    if (dfx == 0) {
      printf("Derivative is zero. Method failed.\n");
      return NAN;
    }

    double x_next = x - fx / dfx;

    if (fabs(x_next - x) < tolerance) {
      printf("Root found after %d iterations.\n", i + 1);
      return x_next;
    }

    x = x_next;
  }

  printf("Maximum iterations reached. Method did not converge.\n");
  return NAN;
}

int main() {
  double initialGuess = 1.0;
  double tolerance = 0.001;
  int maxIterations = 100;

  double root = newtonRaphson(initialGuess, tolerance, maxIterations);

  if (!isnan(root)) {
    printf("Approximate root: %lf\n", root);
  }

  return 0;
}
