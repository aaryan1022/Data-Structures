#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int size = 0;
int freq;

struct node
{
    int val;
    struct node* next;
    struct node* express;
};
typedef struct node* address;

int generate()
{
    srand(time(NULL));
    int k = (rand()%9 + 2);
    return k;
}

void makeList(address head)
{
    printf("Enter the number of elements you want: ");
    scanf("%d", &size);
    printf("element 1: ");
    scanf("%d", &head->val);

    for(int i=1; i<size; i++)
    {
        head->next = (address)malloc(sizeof(struct node));
        head = head->next;  
        printf("element %d: ", i+1);
        scanf("%d", &head->val);
    }
}

void printSkipList(address head)
{
    address head2 = head;
    printf("Your list is: ");
    while(head!=NULL)
    {
        if(head->next == NULL)
        {
            printf("%d", head->val);
        }
        else
        {
        printf("%d->", head->val);
        }
        head = head->next;
    }

    printf("\nYour express nodes are: ");
    while(head2!=NULL)
    {
        printf("%d-->", head2->val);
        if(head2->express == NULL)
        {
            break;
        }
        head2 = head2->express;
    }
    
}

void generateRandomExpress(address head)
{
    freq = generate();
    printf("In every %d nodes,there is an express node \n", freq);
    address head2 = head;

    for(int i = 0; i<size; i++)
    {
        head = head->next;

        if((i+1)%freq == 0)
        {
        head2->express = head;
        head2 = head;
        }
    }
}

void searchSkipList(address head)
{
    int n;
    int e=0;
    int ctr = 0;
    printf("\nEnter the value you want to search for: ");
    scanf("%d", &n);

    while(head!=NULL)
    {
        ctr++;
        if(head->val == n)
        {
            e = 1;
            break;
        }

        if(head->express)
        {
            if((head->express->val)>n)
                head = head->express;
            
            else
                head = head->next;
        }

        else
            head = head->next;
    }


    if(e==0)
    {
        printf("Value does not exist.\n")   ;
    }
    else
    {
        printf("Value exists at node %d \n", ctr);
    }
 }


int main()
{
    address head = (address)malloc(sizeof(struct node));
    makeList(head);
    generateRandomExpress(head);
    printSkipList(head);
    searchSkipList(head); //assuming that the list is in a sorted order
    return 0;
}