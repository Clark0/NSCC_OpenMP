#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
  int i, N = 10;
  double *a, *b;
  double sum = 0.0;
  
  a = (double*) malloc(N * sizeof(double));
  b = (double*) malloc(N * sizeof(double));

  #pragma omp parallel 
  for (i = 0; i < N; i++) {
    a[i] = 1.0;
    b[i] = 1.0;
  }

#pragma omp parallel default(none) shared(sum, a, b, N) private(i) 
{

#pragma omp for reduction(+:sum)
  for (i = 0; i < N; i++) {
    //#pragma omp critical
    sum += (a[i] * b[i]);
  }
}
  printf("Dot Product: %f\n", sum);
  free(a);
  free(b);
}
