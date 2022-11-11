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


    printf("enter size of linked list: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n;i++)
    {
        printf("enter number: ");
        scanf("%d", &arr[i]);
    }
    

    x = malloc(sizeof(struct Node));
    x->val = arr[0];
    address a = x;
    for(int i=1; i<n; i++)
    {
        a->next = malloc(sizeof(struct Node));
        a = a->next;
        a->val = arr[i];
    }


   while(x != NULL)
    {
        printf("%d -> ", x->val);
        x = x->next;
    }





    return 0;
}
