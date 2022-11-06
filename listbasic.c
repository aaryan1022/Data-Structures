#include<stdio.h>
#include<stdlib.h>

/* In this program, I will create a linked list manually without user input and print it.*/

struct Node{
    int val;
    struct Node* next;
};

typedef struct Node nod;

void p(nod* s)
{
    while(s!= NULL)
    {
        printf("%d", s->val);
        s = s->next;
    }
}

int main()
{
    nod* head = malloc(sizeof(struct Node));
    nod* a = malloc(sizeof(struct Node));
    nod* b = malloc(sizeof(struct Node));

    head->val = 1;
    head->next = a;

    a->val = 2;
    a->next = b;
    
    b->val = 3;
    b->next = NULL;

    p(head);

    return 0;
}