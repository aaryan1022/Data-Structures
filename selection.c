#include<stdio.h>
#include<stdlib.h>

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

int min = 0, temp = 0;
for(int i=0; i<n-1; i++)   /*Outer loop: Starts shifting boundary of array to set minimum elements and lock*/
{
    for(int j = i+1; j<n; j++) /*Inner loop: Finds the minimum element to set at position i, finding the ith smallest element*/
    {
        min = i;
        if(arr[j]<arr[min])  
        {
            min = j;
        }
        temp = arr[i];    /*swaps the minimum element and element with i position*/
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
    
 for(int i = 0; i<n; i++)   /*prints sorted array*/
    {
        printf("%d, ", arr[i]);
    }
}

int main()
{
    getArray();
    return 0; ;
}