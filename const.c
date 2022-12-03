#include<stdio.h>
#include<stdlib.h>

int main()
{
const int var = 10;

int *ptr = &var;
*ptr = 12; //Observations: we need to declare ptr as a constant as well to be able to use it as a memory location for a constant. When we do so, we get another error as the constant value cannot be modified

printf("var = %d\n", var);
printf("*ptr = %d\n", *ptr);

return 0;
}