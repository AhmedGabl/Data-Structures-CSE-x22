#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_SIZE 10000

typedef struct node
{
    char data;
    int f;
    struct node *next;
    struct node *left;
    struct node *right;
} node;

void add_node(node **head, char data)
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
node *create_huffman(node *head);
void decode_huffman(const char *s, node *b);

void pr(node* h)
{
    while (h)
    {
        printf(" , %c , ",h->data);
        h=h->next;
    }
    
}
int main()
{
    char s[MAX_SIZE];
    char e[MAX_SIZE];
    scanf(" %[^\n]", s);
    scanf(" %[^\n]", e);
    node *a = NULL, *b = NULL;
    
    for (int i = 0; s[i] != '\0'; i++) add_node(&a, s[i]);
    
    mergesort(&a);
    //pr(a);
    b = create_huffman(a);
    decode_huffman(e, b);
    return 0;
}

// split till 1 element recursivly4
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
// split the list given list into 2 lists
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
// sort each list
node *merge_sorted(node *a, node *b)
{
    node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    else if (a->f == b->f)
    {
        //if (abs(a->data - b->data) == 32) // for sorting small and capital in FIFO
        //{
          //  result= b;
           // result->next = merge_sorted(a,b->next);
        //}
        if (a->data >= b->data )
        {
            result = a;
            result->next = merge_sorted(a->next, b);
        }
        else
        {
            result = b;
            result->next = merge_sorted(a, b->next);
        }
    }
    else if (a->f < b->f)
    {
        result = a;
        result->next = merge_sorted(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge_sorted(a, b->next);
    }
    return (result);
}

node *create_huffman(node *head)
{
    node *temp, *temp2, *interval;
    //    Loops until there are 1 or 2 nodes exist in first level.
    while (head->next->next != NULL && head->next != NULL)
    {
        temp = head;
        temp2 = head->next;
        head = temp2->next;
        temp->next = NULL;
        temp2->next = NULL;
        interval = (node *)malloc(sizeof(node));
        interval->f = temp->f + temp2->f;
        interval->left = temp;
        interval->right = temp2;
        interval->data = '\0';
        //    Add to front:
        if (interval->f < head->f)
        {
            interval->next = head;
            head = interval;
        }
        //    Add to tail or middle.
        else
        {
            node *temp3 = head;
            //    Finding place to add:
            while (temp3->next != NULL && temp3->next->f <= interval->f)
            {
                temp3 = temp3->next;
            }
            interval->next = temp3->next;
            temp3->next = interval;
        }
    }
    //    If there are 2 nodes in first level, links them in one parent root.
    if (head->next->next == NULL)
    {
        interval = (node *)malloc(sizeof(node));
        interval->f = head->f + head->next->f;
        interval->next = NULL;
        interval->data = '\0';
        interval->left = head;
        interval->right = head->next;
        return interval;
    }
    else
    {
        return head;
    }
}

void decode_huffman(const char *s, node *b)
{
    node *temp = b;
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        if (*(s + i) == '0')
            b = b->left;
        else if(*(s+i)=='1')
            b = b->right;
            else break;
        if (b->data != '\0')
        {
            printf( "%c", b->data);
            b = temp;
        }

    }
}

