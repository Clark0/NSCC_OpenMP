#include <omp.h>
#include <stdio.h>

void main() {
    int count = 0;
    #pragma omp parallel
    {
        #pragma omp critical
        count += 1;
    }
    int num = omp_get_thread_num();
    if (num == 0)
        printf("Total number of threads %d\n", count);
}
