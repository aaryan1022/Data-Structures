#include<stdio.h>
#include<stdlib.h>


struct queue
{
    int size;
    int start;
    int end;
    int* arr;
};
typedef struct queue* address;

int isEmpty(address q)
{
    if(q->end == q->start)
        return 1;
    else
        return 0;
}

int isFull(address q)
{
    if(q->end == (q->size - 1))
        return 1;
    else
        return 0;
}

void enqueue(address q, int val)
{
    if(isFull(q) == 1)
        printf("queue full. \n");
    else
    {
        q->end++;
        q->arr[q->end] = val; 
    }
}

int dequeue(address q)
{
    int a = -1;
    if(isEmpty(q) == 1)
        printf("queue empty. \n");
    else
    {
        a = q->arr[q->start];
        q->start++;
    }
    return a;
}


int main()
{
    address q = malloc(sizeof(struct queue));
    q->size = 5;
    q->start = -1;
    q->end = -1;
    q->arr = malloc(q->size * sizeof(int));


    enqueue(q, 0);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    int d = dequeue(q);

//tester

    printf("first dequeued item is: %d \n", d);
    printf("Your queue is: ");
    for(int i= q->start; i<= q->end; i++)
    {
        printf("%d ", q->arr[i]);
    }

    return 0;
}