#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int main()
{
   FILE *input = fopen("C:/Users/Raluca/OneDrive/Desktop/fac/mpi/pr1/test3.txt", "r");

    int v[10000];
    int n = 0, read;

    if(!input)
        printf("Error: Filename \"test1.txt\" not found!\n");

    while(fscanf(input, "%d", &read) != EOF)
    {
        v[++n] = read;
    }
    struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i=1;i<n;i++)
    {
        int k=i;
        for(int j=i+1;j<=n;j++)
            if(v[k]>v[j])
                k=j;
        if(k!=i)
        {
             int aux;
             aux=v[i];
             v[i]=v[k];
             v[k]=aux;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec -start.tv_nsec)) * 1e-9;

    printf("Time taken by program is : %.6f",time_taken);
    return 0;
}
