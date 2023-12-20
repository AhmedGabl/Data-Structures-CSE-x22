#include <stdio.h>
#include <stdlib.h>

int cache_size;

typedef struct cache
{
    unsigned key;
    unsigned data;
    struct cache *next;
    struct cache *prev;
} cache;

void add_new(cache **head, cache **tail, unsigned i, unsigned j)
{
    *head = (cache *)malloc(sizeof(cache));
    (*head)->next = (*head)->prev = NULL;
    (*head)->key = i;
    (*head)->data = j;
    *tail = *head;
}
void add_last(cache **head, cache **tail, unsigned i, unsigned j)
{
    if (*head == NULL && *tail == NULL)
    {
        add_new(head, tail, i, j);
    }
    else
    {
        cache *new = (cache *)malloc(sizeof(cache));
        new->key = i;
        new->data = j;
        new->next = NULL;
        (*tail)->next = new;
        new->prev = *tail;
        (*tail) = new;
    }
}
void del_if_found(cache **head, cache **tail, unsigned i)
{
    cache *temp = *head;
    if (*head == *tail && (*head)->key == i)
    {
        (*head) = (*tail) = NULL;
        free(temp);
    }
    else
    {
        while (temp)
        {
            if (temp->key == i)
            {
                if (temp->next && temp->prev)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                    break;
                }
                else if (temp->next)
                {
                    *head = (*head)->next;
                    (*head)->prev = NULL;
                    free(temp);
                    break;
                }
                else
                {
                    *tail = (*tail)->prev;
                    (*tail)->next = NULL;
                    free(temp);
                    break;
                }
            }
            temp = temp->next;
        }
    }
}

unsigned is_full(cache *head)
{
    unsigned t = 0;
    while (head != NULL)
    {
        t++;
        head = head->next;
    }
    return cache_size == t;
}

void del_LRU(cache **head, cache **tail)
{
    cache *temp = *head;
    if (*tail == *head)
        *tail = *head = NULL;
    else if ((*tail)->prev == *head)
    {
        (*tail)->prev = NULL;
        *head = *tail;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev=NULL;
    }
    free(temp);
}

void insert_cache(cache **head, cache **tail, unsigned i, unsigned j)
{
    if(cache_size == 0)
    {
        printf("Error\n");
    }
    else if (!((*head) && (*tail)))
    {
        add_new(head, tail, i, j);
    }
    else
    {
        del_if_found(head, tail, i);
        if (is_full(*head))
            del_LRU(head, tail);
        add_last(head, tail, i, j);
    }
}

void print_value(cache **h ,cache** t, unsigned i)
{
    cache *head = *h;
    while (head)
    {
        if (head->key == i)
        {
            printf("%u\n", head->data);
            insert_cache(h,t,i,head->data);
            break;
        }
        head = head->next;
    }
    if(!head)
    {
        printf("Not Found\n");
    }
}

int main()
{
    int p, t, temp, temp1;
    scanf("%u", &p);
    scanf("%u", &cache_size);
    cache *head = NULL;
    cache *tail = NULL;

    for (int i = 0; i < p; i++)
    {
        scanf("%u", &t);
        switch (t)
        {
        case 1:
            scanf("%u", &temp);
            scanf("%u", &temp1);
            insert_cache(&head, &tail, temp, temp1);
            break;
        case 2:
            scanf("%u", &temp);
            print_value(&head,&tail,temp);
            break;
        default:
            break;
        }
    }

    return 0;
}