#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* arr = (int*)malloc(5*sizeof(int));
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    arr[4]=4;

    realloc(arr, 6*sizeof(int));    
 
    arr[5] = 5;
    printf("new element is: %d", arr[5]);
    return 0;
}