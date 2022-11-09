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

void sortList(address s, int n)
{
    int x;
    int m;
    int temp;
    address a = s;
    address b = s;
    address min=s;
   for(int i=0; i<n; i++)
   {
     for(int j=i+1; j<n; j++)
     {
       b = b->next;
       v = b->val;
       m = min->val;
       if(m>v)
       {
         min = b;
       }
     }
     temp = a;
     a = min;
     min = temp;
     b = min->next;
   }
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

    sortList(head, n);   /*Calls the function to print linked list*/
}




int main()
{
    createList();
   return 0;
}