#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct num_list num_list;

struct num_list
{
    int data ;
    struct num_list *next ;
    struct num_list *prev;
};


num_list* add_node(num_list * head,int data) {
    num_list* node = (num_list *) malloc(sizeof(num_list));
    if(node==NULL)
     {
         //printf("\n UNABLE TO ALLOCATE MEMORY \n EXITING PROGRAM \n");
         exit(1);
     }
    node->data = data;
    node->prev = head ;
    node->next = NULL;
    return node;
}


int pal_check(num_list *s,num_list *e) {
    if(s->next == e->prev||s==e->prev||s->next==e)
    if (s->data==e->data)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return ( (s->data == e->data )&& pal_check(s->next,e->prev))?1:0;
}




int main (){
num_list * temp , * temp1 , *head;
int x,t;

scanf("%d",&x);

if(x<0)
    x*= (-1);

if(x==0)
{
    printf("YES");
    return 0;
}

for (int i = x ; i > 0 ; i=i/10)
{
    t=i%10;
    if (i==x)
    {
        head = add_node(NULL,t);
        temp = head ;
    }
    else
    {
        temp1 = add_node(temp,t);
        temp->next = temp1;
        temp = temp1 ;
    }
}



    if (pal_check(head,temp))
        printf("YES");
    else
        printf("NO");

return 0;
}