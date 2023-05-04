#include <stdio.h>
#include <sys/time.h>

int partition(int arr[], int st, int dr)
{
    int pivot = arr[dr];
    int i= (low- 1);
    for (int j = st; j <= dr - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int aux;
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
        }
    }
    int aux;
        aux=arr[i+1];
        arr[i+1]=arr[dr];
        arr[dr]=aux;
    return (i + 1);
}

void quickSort(int arr[], int st, int dr)
{
    if (st < dr) {
        int pi = partition(arr, st, dr);
        quickSort(arr, st, pi - 1);
        quickSort(arr, pi + 1, dr);
    }
}

int main()
{
    FILE *input = fopen("C:/Users/Raluca/OneDrive/Desktop/fac/mpi/pr1/test3.txt", "r");

    int v[10000];
    int n = -1, read;
    double time_spent = 0.0;
    if(!input)
        printf("Error: Filename \"test1.txt\" not found!\n");

    while(fscanf(input, "%d", &read) != EOF)
        v[++n] = read;

    n = sizeof(v) / sizeof(v[0]);
struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

    quickSort(v, 0, n - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec -start.tv_nsec)) * 1e-9;

    printf("Time taken by program is : %.6f",time_taken);
    return 0;
}

