#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int main()
{
    FILE *input = fopen("C:/Users/Raluca/OneDrive/Desktop/fac/mpi/pr1/test3.txt", "r");

    int v[10000];
    int n = 0, read;

    if(!input)
        printf("Error: Filename \"test2.txt\" not found!\n");

    while(fscanf(input, "%d", &read) != EOF)
    {
        v[++n] = read;
    }

    int ok=1;
    struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);
    while(ok)
    {
        ok=0;
        for (int i=1;i<n;i++)
            if(v[i]>v[i+1])
                {
                    int aux;
                    aux=v[i];
                    v[i]=v[i+1];
                    v[i+1]=aux;
                    ok=1;
                }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec -start.tv_nsec)) * 1e-9;

    printf("Time taken by program is : %.6f",time_taken);

    return 0;
}
