#include <omp.h>
#include <stdio.h>

void main() {
int count = 0;
#pragma omp parallel
{
#pragma omp critical
    count += 1;
}
    printf("Total number of threads %d\n", count);
}
