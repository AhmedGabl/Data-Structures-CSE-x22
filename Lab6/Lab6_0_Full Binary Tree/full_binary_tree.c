#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;
typedef struct queue
{
    struct node *tree_node;
    struct queue *next;
} que;

void enqueue(que **head, que **tail, node *data)
{
    que *nod = (que *)malloc(sizeof(que));
    if (nod == NULL)
    {
        exit(1);
    }
    nod->tree_node = data;
    nod->next = NULL;
    if (*head == NULL && *tail == NULL)
    {
        *head = nod;
        *tail = *head;
    }
    else
    {
        (*tail)->next = nod;
        (*tail) = nod;
    }
}

node *dequeue(que **head,que** tail)
{
    que *temp;
    node *t;
    t = (*head)->tree_node;
    temp = *head;
    if ((*head) == (*tail))
        *tail = *head = NULL;
    else
    *head = (*head)->next;    
    free(temp);
    return t;
}

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

unsigned check_full(node *root)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if ((root->left) && (root->right))
        return (check_full(root->left) && check_full(root->right));
    return 0;
}

node *level_order_tree(int arr[], int n)
{
    que *front = NULL;
    que *rear = NULL;
    int i = 0;

    node *root = add_node(arr[i]);
    enqueue(&front, &rear, root);

    i++;

    while (i < n)
    {
        node *current = dequeue(&front,&rear);
        if (i < n && arr[i] != -1)
        {
            node *temp = add_node(arr[i]);
            current->left = temp;
            enqueue(&front, &rear, temp);
        }

        if (i + 1 < n && arr[i + 1] != -1)
        {
            node *temp = add_node(arr[i + 1]);
            current->right = temp;
            enqueue(&front, &rear, temp);
        }
        i += 2;
    }
    return root;
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

    node *root = NULL;
    root = level_order_tree(arr, x);

    if (check_full(root))
        printf("YES");
    else
        printf("NO");
    return 0;
}
