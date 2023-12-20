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

typedef struct mfe
{
    int element;
    int times;
    struct mfe *next;
} mfe;

typedef struct out
{
    int d;
    struct out *next;
} out;

out *add_out_node(out *h, int d)
{
    out *node = (out *)malloc(sizeof(out));
    // node->next = NULL;
    node->d = d;
    if (h == NULL)
    {
        node->next = NULL;
        return node;
    }
    else
    {
        node->next = h;
        return node;
    }
}

int max(mfe *head);

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

node *dequeue(que **head, que **tail)
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
        node *current = dequeue(&front, &rear);
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

void add_element(mfe **temp, int d)
{
    mfe *node = (mfe *)malloc(sizeof(mfe));
    if (node == NULL)
        return;
    int flag = 0;
    if ((*temp) == NULL)
    {
        node->next = NULL;
        node->element = d;
        node->times = 1;
        *temp = node;
        // printf("\n%d 1 \n",node->element);
        return;
    }
    else
    {
        mfe *temp1;
        temp1 = *temp;
        while ((temp1) != NULL)
        {
            if ((temp1)->element == d)
            {
                flag = 1;
                (temp1)->times += 1;
                free(node);
                return;
            }
            temp1 = temp1->next;
        }
    }
    if ((*temp) != NULL && flag != 1)
    {
        node->next = *temp;
        node->element = d;
        node->times = 1;
        *temp = node;
    }
}

mfe *temp = NULL;

void check_mfe(node *root)
{
    if (root != NULL)
    {
        add_element(&temp, root->data);
        check_mfe(root->left);
        check_mfe(root->right);
    }
}
void sort(out **final)
{
    out *t, *t1;
    t = *final;
    t1 = t;
    int g;

    while (t)
    {
        while (t1)
        {
            if (t->d > t1->d)
            {
                g = t->d;
                t->d = t1->d;
                t1->d = g;
            }
            t1 = t1->next;
        }
        t = t->next;
        t1=t;
    }
}


int main()
{
    long int x;
    scanf(" %ld ", &x);
    int arr[x];
    for (unsigned i = 0; i < x ; i++)
    {
        scanf("%d", &arr[i]);
    }
    node *root = NULL;
    root = level_order_tree(arr, x);
    check_mfe(root);

    int t = max(temp);
    out *final = NULL;
    while (temp != NULL)
    {
        if (temp->times == t)
        {
            final = add_out_node(final, temp->element);
        }
        temp = temp->next;
    }
    sort(&final);

    while (final)
    {
        printf("%d\n", final->d);
        final = final->next;
    }
return 0;
}

int max(mfe *head)
{
    int y;
    y = head->times;
    while (head != NULL)
    {
        if (y < head->times)
        {
            y = head->times;
        }
        head = head->next;
    }
    return y;
}
