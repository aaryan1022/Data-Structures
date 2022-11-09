#include <stdio.h>
#include <stdlib.h>


int main()
{
    struct Node
    {
        int val;
        struct Node* next;
    };
    typedef struct Node* address;
    address x;
    x = malloc(sizeof(struct Node));
    address a = x;



    int arr[] = {};
    printf("enter size of linked list: ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n;i++)
    {
        printf("enter number: ");
        scanf("%d", &arr[i]);
    }
    

    for(int i=0; i<n; i++)
    {
        a->val = arr[i];
        a = a->next;
        a = malloc(sizeof(struct Node));
    }


   while(x != NULL)
    {
        printf("%d -> ", x->val);
        x = x->next;
    }





    return 0;
}