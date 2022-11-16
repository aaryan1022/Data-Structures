#include<stdio.h>
#include<stdlib.h>


void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int * arr, int n, int i)
{
    int max = i;

    int l = i*2 + 1;
    int r = i*2 + 2;

    if(l<n && arr[l]>arr[max])
    {
        max = l;
    }

    if(r<n && arr[r]>arr[max])
    {
        max = r;
    }

    if(max!=i)
    {
        swap(&arr[i], &arr[max]);

        heapify(arr, n, max);

    }
}



int * heapsort(int * arr, int n)
{

    for(int i = (n/2)-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }

    return arr;
}

int main()
{
    printf("Enter the size of array you want: ");
    int n;
    scanf("%d", &n);
    int * arr = malloc(n*sizeof(int)) ;

    for(int i = 0; i<n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    } 

    printf("original array: ");
    for(int i = 0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }

    arr = heapsort(arr, n);    

     printf("sorted array: ");
    for(int i = 0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0; ;
}