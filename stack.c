#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};
typedef struct stack* address;

int isEmpty(struct stack* p)
{
    if(p->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack* q)
{
    if(q->top == (q->size - 1))
        return 1;
    else
        return 0;
}

void push(address s, int val)
{
    if(isFull(s)==1)
        printf("stack overflow: stack full, cannot push. \n");
    else
        {
            s->top++;
            s->arr[s->top] = val;
        }
}

int pop(address s)
{
    if(isEmpty(s)==1)
    {
        printf("stack is empty, cannot pop. \n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int main()
{
    struct stack *s = malloc(sizeof(struct stack*));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
//tester
    int popped = pop(s);
    printf("popped value is: %d", popped);

    return 0;
}