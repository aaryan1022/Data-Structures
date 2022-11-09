#include<stdio.h>
#include<stdlib.h>

struct Node{            /*creating a struct to store the node*/
    int val;           /*This will store the value in the node*/
    struct Node* next;      /*This will store the address of the next node*/
};

typedef struct Node* address;    /*Creating an alias for creating memory addresses for the node*/

void halvedList(address s, int ctr)  //prints the halved list
{
    ctr = ctr/2;
    printf("Your linked list is:");
    address a = s;
    while(s!= NULL) /*Terminates on the last node that points to null address*/
    {
        printf("%d -> ", s->val);   /*Prints the values of nodes*/
        s = s->next;
    }
    printf("\n Your halved linked list is:");
    for(int i=0; i<=ctr; i++)  /*Terminates on the last node that points to null address*/
    {
        printf("%d -> ", a->val);   /*Prints the values of nodes*/
        a = a->next;
    }
    printf("\n");
}


void createList()
{
   address head = malloc(sizeof(struct Node));     /*allocates space for the node at the specific address*/
   printf("Enter number: ");
    scanf("%d", & head->val);   /*Gets the value of first node from user*/
    address s = head;
    int i = 1;
    int ctr = 0;
    while(i==1)
    {
        printf("continue? (1/0): ");  //checks if the user wants to continue the linked list
        scanf("%d", &i);
        if(i == 1)
        {
        printf("Enter number: ");   
        s->next =  malloc(sizeof(struct Node));    /*assigns the address of the next node*/
        s=s->next;
        scanf("%d", &s->val);  /*Takes the value for the next node*/
        ctr++;   //counts the number of elements entered by the user
        }
        else if(i == 0)
        {
            break;
        }
        else
        {
            printf("wrong input");
            break;
        }
    }

    halvedList(head, ctr);   /*Calls the function to print halved linked list*/
}




int main()
{
    createList();
   return 0;
}