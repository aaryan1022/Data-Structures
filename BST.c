#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* left;
    struct node* right;
};

typedef struct node* address;

address search(address root, int val )
{
    if(root == NULL)
    return NULL;

    if(val > root->val)
    {
        search(root->right, val);
    }
    else if(val < root->val )
    {
        search(root->left, val);
    }
    

        return root;
    
}


void insert(address root, int val)
{
    if(root == NULL)
    {
         root = malloc(sizeof(struct node));
         root->val = val;
        return;
    }

    else if(val > root->val)
    {
        if(root->right)
            insert(root->right, val);
        else
        { 
        root->right = malloc(sizeof(struct node));
        root->right->val = val;
        }
            
    }

    else if(val < root->val)
    {
        if(root->left)
            insert(root->left, val);
        else{
             root->left = malloc(sizeof(struct node));
             root->left->val = val;
        }
    }

}

void inorder(address root)
{
    if(root->left)
    {
        inorder(root->left);
    }
    if(root)
    {
        printf("%d", root->val);
    }
    if(root->right)
    {
        inorder(root->right);
    }
}



int main()
{
    int n;
    printf("enter the size of array, that will be made into a binary tree.");
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        printf("enter number: ");
        scanf("%d", &arr[i]);
    }

    /*  for(int i = 0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }*/ 

    address root = malloc(sizeof(struct node));
    root->val = arr[0];

    for(int i=1; i<n; i++)
    {
        insert(root, arr[i]);
    }
    
    inorder(root);
   // printf("%d", root->right->val);

    return 0;
}