#include <stdio.h>
#include <stdlib.h>

typedef struct num_list num_list;


struct num_list
{
    int data;
    struct num_list *next;
 //   struct num_list *prev;
};

num_list *enqueue(num_list *head, int data)
{
    num_list *node = (num_list *)malloc(sizeof(num_list));
    if (node == NULL)
    {
        // printf("\n UNABLE TO ALLOCATE MEMORY \n EXITING PROGRAM \n");
        exit(1);
    }
    node->data = data;
   // node->prev = head;
    node->next = NULL;
    return node;
}

num_list *dequeue(num_list *head)
{
    num_list* temp;
    temp = head;
    head=head->next;
    free(temp);
    return head;
}


void print_num_list(num_list *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
        if(head)
        printf(",");
    }
}


int main()
{
num_list * head=NULL ,*tail =NULL , *temp;

unsigned x,flag,t;

scanf("%d",&x);

if(x < 0)
    exit(1);

for (unsigned i = 0 ; i < x ; i++)
{
    scanf("%d",&flag);
    if (flag==1)
    {
        scanf("%d",&t);
        if (head==NULL)
    {
        head = enqueue(NULL,t);
        tail = head ;
    }
    else
    {
        temp = enqueue(tail,t);
        tail->next = temp;
        tail = temp ;
    }
    }
    else if (flag==2)
    {
        if(!head)
                {
                    //exit(1);
                    continue;
                }
                else 
                head = dequeue(head);
    }
    else if (flag==3)
    {
        if (!head)
            {
                printf("Empty\n");
            }
            else
            {
                print_num_list(head);
                printf("\n");
            }
    }
    else 
    continue;
}
return 0;
}
