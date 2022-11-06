#include<stdio.h>
#include<stdlib.h>

int main()
{
    char s[20];
    printf("enter your name: ");
    fgets(s, 20, stdin);
    printf("Your name is %s \n", s);
    return 0;
}