#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main()
{
   FILE *input = fopen("C:/Users/Raluca/OneDrive/Desktop/fac/mpi/pr1/test1.txt", "r");
    int v[10001];
    int n = 0, read;
    double time_spent = 0.00000;
    if(!input)
        printf("Error: Filename \"test1.txt\" not found!\n");

    while(fscanf(input, "%d", &read) != EOF)
        v[++n] = read;

    int t;
    clock_t begin, end ;
    begin = clock();

    for(int i=2;i<=n;i++)
    {
        t=v[i];
        int k=i-1;
        while(t<v[k]&&k>=1)
        {
            v[k+1]=v[k];
            k--;
        }
        v[k+1]=t;
    }
    end = clock();
    double duration = ((double)end - begin)/CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", duration);

    return 0;
}
