#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a = 5;
    int* address = &a;
    printf("value of a is: %d", *address);
    return 0;
}