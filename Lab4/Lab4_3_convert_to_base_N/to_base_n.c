#include <stdio.h>
#include <stdlib.h>

typedef struct num_list num_list;

num_list *evaluate(num_list *head, int i, int N);

struct num_list
{
    int data;
    struct num_list *previous;
};

num_list *push(num_list *head, int data)
{
    num_list *node = (num_list *)malloc(sizeof(num_list));
    if (node == NULL)
    {
        exit(1);
    }
    node->data = data;
    node->previous = head;
    return node;
}

void print_num_list(num_list *head)
{
    while (head)
    {
        if (head->data >= 10)
        {

            switch (head->data)
            {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            }
        }
        else
            printf("%d", head->data);
        head = head->previous;
    }
}

int main()
{
    num_list *head = NULL;

    unsigned x, N;
    scanf("%d", &x);
    scanf("%d", &N);

    head = evaluate(head, x, N);
    print_num_list(head);
    return 0;
}

num_list *evaluate(num_list *head, int i, int N)
{
    int t = 0;
    if (i != 0)
        t = i % N;
    else
        return head;

    head = push(head, t);
    head = evaluate(head, i / N, N);
    return;
}