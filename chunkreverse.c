#include<stdio.h>
#include<stdlib.h>

struct Node{            /*creating a struct to store the node*/
    int val;           /*This will store the value in the node*/
    struct Node* next;      /*This will store the address of the next node*/
};

typedef struct Node* address;    /*Creating an alias for creating memory addresses for the node*/

void printList(address s)
{
    printf("Your linked list is: ");
    while(s!= NULL)  /*Terminates on the last node that points to null address*/
    {
        printf("%d -> ", s->val);   /*Prints the values of nodes*/
        s = s->next;
    }
    printf("\n");
}



address chunkreverse(address head, int k)
{
    address previous, current, next;
    int ctr = 0;
    previous = NULL;
    current = head;

    while(current!=NULL && ctr!=k)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        ctr++;
    }

    if(next!=NULL)
        head->next = chunkreverse(next, k);

    return previous;   
}


void createList()
{
   int n;
   printf("enter the size of linked list you want: ");
   scanf("%d", &n);    /*Takes the size of linked list as user input*/
   
   address head = malloc(sizeof(struct Node));     /*allocates space for the node at the specific address*/
   printf("Enter number: ");
    scanf("%d", & head->val);   /*Gets the value of first node from user*/
    address s = head;

    int i = 1;
    while(i<n)
    {
        printf("Enter number: ");   
        s->next =  malloc(sizeof(struct Node));    /*assigns the address of the next node*/
        s=s->next;
        scanf("%d", &s->val);  /*Takes the value for the next node*/
        i++;
    }

    printList(head);   /*Calls the function to print linked list*/

    int k;
    printf("Enter the value of chunk to reverse: ");
    scanf("%d", &k);
    address newHead = chunkreverse(head, k);

    printList(newHead);
}




int main()
{
    createList();
   return 0;
}