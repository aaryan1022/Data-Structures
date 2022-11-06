#include<stdio.h>
#include<stdlib.h>

struct Node{            /*creating a struct to store the node*/
    int val;           /*This will store the value in the node*/
    struct Node* next;      /*This will store the address of the next node*/
};

typedef struct Node* address;    /*Creating an alias for creating memory addresses for the node*/

void printList(address s)
{
    printf("Your linked list is:");
    while(s!= NULL)  /*Terminates on the last node that points to null address*/
    {
        printf("%d -> ", s->val);   /*Prints the values of nodes*/
        s = s->next;
    }
    printf("\n");
}


void reverseList(address a)
{
    address before = NULL;
    address current = a;
    address after = NULL;

    while(current != NULL)  /*reversing process terminates if current shifts all the way to null */
    { 
        after = current->next;  /*After shifts to the next node address*/
        current->next = before;     /*For the first node, the head starts pointing to the null address. All the further nodes start pointing to the previous nodes.*/
        before = current;      /*The before shifts to the current node address*/
        current = after;       /*The current shifts to the next node address*/
    }
    printList(before);
}

void createList()
{
   int n;
   printf("enter the size of linked list you want: ");
   scanf("%d", &n);    /*Takes the size of linked list as user input*/
   
   address head = malloc(sizeof(struct Node));     /*allocates space for the node at the specific address*/
   printf("Enter number: ");
    scanf("%d\n", & head->val);   /*Gets the value of first node from user*/
    address s = head;

    int i = 1;
    while(i<n)
    {
        printf("Enter number: ");   
        s->next =  malloc(sizeof(struct Node));    /*assigns the address of the next node*/
        s=s->next;
        scanf("%d \n", &s->val);  /*Takes the value for the next node*/
        i++;
    }
    
    reverseList(head);
}




int main()
{
    createList();
   return 0;
}