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