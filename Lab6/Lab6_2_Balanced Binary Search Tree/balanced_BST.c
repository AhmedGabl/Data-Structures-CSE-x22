#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *add_node(int a)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        exit(1);
    }
    new->data = a;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* balanced_bst(int arr[], int s, int e)
{
    if (s > e)
      return NULL; 
    int mid = (s + e)/2;
    node *root = add_node(arr[mid]);
    root->left =  balanced_bst(arr, s, mid-1);
    root->right = balanced_bst(arr, mid+1, e);
    return root;
}
void pretorder(node *root)
{
    if (root != NULL)
    {        
        printf("%d", root->data);
        if(!(root->right ==NULL))
            printf(",");
        pretorder(root->left);
        if(!(root->right ==NULL))
            printf(",");
        pretorder(root->right);
    }
}
int main()
{
    unsigned x;
    scanf("%d", &x);
    int arr[x];
    for (unsigned i = 0; i < x; i++)
    {
        scanf("%d", arr + i);
    }

    node *root = balanced_bst(arr,0,x-1);
    pretorder(root);

}
