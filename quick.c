#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n)
{
        for(int i = 0; i<n; i++)   /*Accepts n elements from user to make array*/
    {
        printf("%d ", arr[i]);
    } 
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i]; //swaps the elements
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) //partitions thr array between elements smaller than pivot and greater than pivot
{
    int j = low-1;
    int pivot = arr[high];  //pivot begin to set as end value
    for(int i=low;i<=high; i++)
    {
        if(arr[i]<pivot)  //arranges the elements 
        {
            j++;
            swap(arr, i,j);
        }
    }
    swap(arr, j+1, high); //puts pivot in correct position
    return (j+1);
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
  int pivot = partition(arr, low, high); //gives starting and end value

  quickSort(arr, low, pivot-1); //sorts elements below pivot
  quickSort(arr, pivot+1, high); //sorts elements above pivot
    }
}

void getArray()
{
    printf("Enter the size of array you want: "); 
    int n;
    scanf("%d", &n);   /*Accepts int input from user to set array size*/
    int arr[n];

    for(int i = 0; i<n; i++)   /*Accepts n elements from user to make array*/
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    } 
    quickSort(arr, 0, n-1);
    printArray(arr, n);
}


int main()
{
    getArray();
    return 0; 
}