#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k,n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;j = 0;k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    FILE *input = fopen("C:/Users/Raluca/OneDrive/Desktop/fac/mpi/pr1/test1.txt", "r");

    int v[10000];
    int n = -1, read;

    if(!input)
        printf("Error: Filename \"test1.txt\" not found!\n");

    while(fscanf(input, "%d", &read) != EOF)
     v[++n] = read;
    struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

     mergeSort(v, 0, n);

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec -start.tv_nsec)) * 1e-9;
    printf("Time taken by program is : %.6f",time_taken);

    return 0;
}
