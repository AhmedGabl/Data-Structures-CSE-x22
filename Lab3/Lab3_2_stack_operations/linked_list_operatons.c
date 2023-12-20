#include<stdio.h>
#include<stdlib.h>

typedef struct num_list num_list;

void swap(num_list* i,num_list* j);


struct num_list
{
    int data ;
    struct num_list *next ;
    struct num_list *prev;
};

num_list* create_node(num_list * head,int data) {
    num_list* node = (num_list *) malloc(sizeof(num_list));
    if(node==NULL)
     {
         printf("\n UNABLE TO ALLOCATE MEMORY \n EXITING PROGRAM \n");
         exit(1);
     }
    node->data = data;
    node->prev = head ;
    node->next = NULL;
    return node;
}

void reverse(num_list *s,num_list *e){
    while(!(s==e))
    {
        swap(s,e);
        if(s==e->prev||s->next==e)
            break;
        s=s->next;
        e=e->prev;
    }
}


void print_num_list(num_list* head) {
    while (head) {
        printf("%d \n", head->data);
        head = head->next;
    }
}

num_list* find_tail(num_list* head,int N){
    for (int i = 0; i < (N-1); i++)
    {
        head=head->next;
    }
    return head;
}


int main (){
num_list  *t_head, *t_tail,*t1 , * temp, *head, *tail ;
int t;
unsigned x,n;

scanf("%d",&x);
scanf("%d",&n);
for (int i = 0 ; i < x ; i++)
{
    scanf("%d",&t);

    if (i==0)
    {
        head = create_node(NULL,t);
        tail = head ;
    }
    else
    {
        temp = create_node(tail,t);
        tail->next = temp;
        tail = temp ;
    }
}

t=x/n;
t_head=head;
t_tail=tail;
for (int i = 0; i < t; i++)
{
    t_tail = find_tail(t_head,n);
    t1=t_tail->next;
    reverse(t_head,t_tail);
    t_head = t1;
}


print_num_list(head);
return 0;
}


void swap(num_list* i,num_list* j){
    int temp ;
    temp = i->data;
    i->data=j->data ;
    j->data = temp;
}
