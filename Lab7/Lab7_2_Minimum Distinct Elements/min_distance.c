#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    unsigned long long int data;
    unsigned f;
    struct node *next;
} node;

void add_node(node **head, unsigned long long int data)
{
    int flag = 0;

    if ((*head))
    {
        node *t = *head;
        while (t)
        {
            if (data == t->data)
            {
                t->f++;
                flag = 1;
                break;
            }
            t = t->next;
        }
    }
    if (flag == 0)
    {
        node *new_node = (node *)malloc(sizeof(node));
        if (!new_node)
            exit(0);

        new_node->data = data;
        new_node->f = 1;
        new_node->next = (*head);
        (*head) = new_node;
    }
}

void mergesort(node **temp);
node *merge_sorted(node *a, node *b);
void split(node *a, node **front, node **back);
int count_distinct(node *head);

void remove_r(node **h, unsigned r)
{
    node *head = *h;
    while (r)
    {
        if (head && head->f >= 1)
        {
            head->f--;
        }
        if(head->f == 0)
        head = head->next;
        r--;
    }
}

int main()
{
    unsigned x, r;
    unsigned long long int t;
    node *a = NULL;
    scanf("%d", &x);
    scanf("%d", &r);
    for (unsigned i = 0; i < x; i++)
    {
        scanf("%lld", &t);
        add_node(&a, t);
    }
    mergesort(&a);
    remove_r(&a, r);
    printf("%d ", count_distinct(a));
    return 0;
}

void mergesort(node **temp)
{
    node *head = *temp;
    node *a;
    node *b;
    if ((head == NULL) || (head->next == NULL))
        return;
    split(head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    *temp = merge_sorted(a, b);
}

void split(node *a, node **front, node **back)
{
    node *fast;
    node *slow;
    if (a == NULL || a->next == NULL)
    {
        *front = a;
        *back = NULL;
    }
    else
    {
        slow = a;
        fast = a->next;
        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = a;
        *back = slow->next;
        slow->next = NULL;
    }
}

node *merge_sorted(node *a, node *b)
{
    node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    else if (a->f <= b->f)
    {
        result = a;
        result->next = merge_sorted(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge_sorted(a, b->next);
    }
    return result;
}

int count_distinct(node *head)
{
    int i = 0;
    while (head)
    {
        if ((head)->f > 0)
            i++;
        head = head->next;
    }
    return i;
}