#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n) 
{
    int temp;
    for(int i=1; i<n; i++)  //going from first to last element of array
    {
        for(int j=i; j>0; j--)  //going from ith element to first element, sets smallest value in the unsorted section to the ith element
        {
            if(arr[j-1]>arr[j])  //swaps elements if the previous index has a larger element
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("\n Sorted array: ");
     for(int i = 0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }
}

void getArray()  
{
    printf("Enter the size of array you want: ");
    int n;   //gets array size from user 
    scanf("%d", &n);  
    int arr[n];

    for(int i = 0; i<n; i++)  //gets array elements from user
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    } 


     printf("Unsorted array: ");
 for(int i = 0; i<n; i++)  //prints unsorted array
    {
        printf("%d, ", arr[i]);
    }
     insertionSort(arr, n);
}

int main()
{
    getArray();
    return 0; ;
}