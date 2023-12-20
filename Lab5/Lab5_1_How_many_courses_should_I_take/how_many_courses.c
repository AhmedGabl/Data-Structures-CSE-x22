#include <stdio.h>
#include <stdlib.h>

typedef struct num_list num_list;

struct num_list
{
    unsigned num_days, last_day;
    int priority;
    struct num_list *next;
    struct num_list *prev;
};

unsigned fulldays(num_list* head)
{ unsigned x=0;
    while (head)
    {
        x+= head->num_days;
        head=head->next;
    }
    return x;
}
/**
num_list *enqueue(num_list *head, unsigned num_days, unsigned last_day)
{

    num_list *node = (num_list *)malloc(sizeof(num_list));
    if (node == NULL)
    {
        printf("\n UNABLE TO ALLOCATE MEMORY \n EXITING PROGRAM \n");
        exit(1);
    }

    if(head)
       node->priority = (fulldays(head) + num_days <= last_day)?1:0;
    else 
       node->priority = num_days <=last_day?1:0;

if(node->priority == 1 )
{
    node->num_days = num_days;
    node->last_day = last_day;
    node->prev = head;
    node->next = NULL;
return node;
}
else
{
    free(node);
    return head;
}
}


/**/




num_list *enqueue(num_list *head, unsigned num_days, unsigned last_day)
{
    num_list *node = (num_list *)malloc(sizeof(num_list));
    if (node == NULL)
    {
        // printf("\n UNABLE TO ALLOCATE MEMORY \n EXITING PROGRAM \n");
        exit(1);
    }
        node->priority = 10000-last_day - num_days;
        node->num_days = num_days;
        node->last_day = last_day;
        node->prev = head;
        node->next = NULL;
        return node;
}
/**
num_list *enqueue(num_list *head,unsigned full_days, unsigned num_days, unsigned last_day)
{

    if((head && ((full_days + num_days) <= last_day))|| ( !head &&(num_days <= last_day)))
    {
        num_list *node = (num_list *)malloc(sizeof(num_list));
        if (node == NULL)
        {
            printf("\n UNABLE TO ALLOCATE MEMORY \n EXITING PROGRAM \n");
            exit(1);
        }
        node->priority = 1;
        node->num_days = num_days;
        node->last_day = last_day;
        node->prev = head;
        node->next = NULL;
        return node;
    }
    else
    {
        return NULL;
    }
}
**/
int how_many_courses(num_list *head)
{
    int num_courses = 0;
    int full_days = fulldays(head);
    int t=0;
    while (head)
    {
        if (((t + head->num_days) <= head->last_day))
          {
              t+=head->num_days;
              num_courses++;
          }
        head = head->next;
    }
    return num_courses;
}

void printit(num_list *head)
{
    while (head)
    {
        printf("\n %u %u  %d \n", head->num_days, head->last_day, head->priority);
        head = head->next;
    }
}

void swap(num_list* i,num_list* j){
    int temp ;
    temp = i->num_days;
    i->num_days=j->num_days ;
    j->num_days = temp;
    
    temp = i->priority;
    i->priority=j->priority ;
    j->priority = temp;
    
    temp = i->last_day;
    i->last_day=j->last_day ;
    j->last_day = temp;
    
}

void sort_priorities(num_list* head)
{
    num_list * t;
    t=head->next;

while(head->next)
{
    while(t)
    {
        if (head->priority <= t->priority)
        {
            swap(head,t);
        }
        t=t->next;
    }
    head=head->next;
    t= head->next;
}
}



int main()
{
    num_list *head = NULL, *tail = NULL, *temp;

    unsigned x, num_days, last_day;

    scanf("%d", &x);
    
    for (int i = 0; i < x; i++)
    {
        scanf("%u%u", &num_days, &last_day);
        if (head == NULL)
        {
            head = enqueue(NULL, num_days, last_day);
            tail = head;
        }
        else
        {
            temp = enqueue(tail, num_days, last_day);
            tail->next = temp;
            //if(temp)
            tail = temp;
        }
    }
    sort_priorities(head);

  //  printit(head);
    printf("%d", how_many_courses(head));

    return 0;
}
