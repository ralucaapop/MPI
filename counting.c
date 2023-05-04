#include <stdio.h>
#include <sys/time.h>
int main()
{
    FILE *input = fopen("C:/Users/Raluca/OneDrive/Desktop/fac/mpi/pr1/test1.txt", "r");

    int v[10000],f[10000]={0}, y[10000];
    int n = 0, read;
    if(!input)
        printf("Error: Filename \"test1.txt\" not found!\n");


    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    while(fscanf(input, "%d", &read) != EOF)
    {
        v[++n] = read;
        f[read]++;
    }

    for(int i=2;i<=10000;i++)
            f[i]=f[i-1]+f[i];
    for (int i=n;i>=1;i--)
            y[f[v[i]]]=v[i], f[v[i]]--;

     clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec -start.tv_nsec)) * 1e-9;
    printf("%f", time_taken);
    return 0;
}
