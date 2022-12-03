#include <stdio.h>
#include <stdlib.h>

int * mem(int n) {
    int s;
	int * p = &s;
     s = n*n;
	return p; //this shows that a variable lies within the block scope but memory allocation does not
}

int main() {
	int * sqr = mem(5);
	printf("%d.\n", *sqr);
	return 0;
}