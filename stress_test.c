#include<stdio.h>
#include<stdlib.h>

// changing increment, seeing at what point you end up with an extra loop

int main(int argc, char** argv){

    float i;
    float increment = 0.000000001;    
    float n = 0.00000001; 
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    return 0;
}