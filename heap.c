#include<stdio.h>
#include<stdlib.h>


int size = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void print(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d, ", arr[i]);
    }
}


void heapify(int arr[], int i, int size)
{
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;

    if(arr[left]<size)
    {  
         if(arr[left]>arr[i])
          largest = left;
    }
    if(arr[right]<size)
    {
        if(arr[right]>arr[i])
          largest = right;
    }


    if(largest!=i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, i, size);
    }
}

void insert(int arr[], int val)
{
    if(size == 0)
    {
        arr[0] = val;
        size++;
    }
    else
    {
        arr[size] = val;
        size++;
        for(int i= (size/2)-1; i>=0; i--)
        {
            heapify(arr, i, size);
        }
    }
}

void delete(int arr[], int val)
{
    int n;
    for(int i=0; i<size; i++)
    {
        if(arr[i] == val)
        {
            n = i;
            break;
        }
    }
    swap(&arr[n], &arr[size-1]);
   
    size = size - 1;
    for(int j = (size/2)-1; j>=0; j--)
    {
        heapify(arr, j, size);
    }
    
}

void heapsort(int arr[])
{
    for(int i = (size-1); i>=0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i);
        print(arr, size);
    }
}


int main()
{
    int arr[10];
    insert(arr, 0);
    insert(arr, 1);
    insert(arr, 2);
    insert(arr, 3);
    insert(arr, 4);
    insert(arr, 5);
    insert(arr, 6);
    delete(arr, 6);
    heapsort(arr);

    print(arr, size);

    return 0;
}