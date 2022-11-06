#include<stdio.h>
#include<stdlib.h>

void getArray()
{
    printf("Enter the size of array you want: ");
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i<n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    } 

    int max, index;
    for(int i=0; i<n; i++)
    {
        for(int j=n-i-1;j>=0;j--)
        {
         max=0, index = 0;
            if(arr[j]>max)
            {
            max = arr[j];
            index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[n-i-1];
        arr[n-i] = temp;
    }

    
 for(int i = 0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int main()
{
    getArray();
    return 0; ;
}