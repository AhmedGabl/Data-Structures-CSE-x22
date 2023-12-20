#include<stdio.h>
#include<stdlib.h>

typedef struct num_list num_list;

struct num_list
{
    unsigned data ;
    struct num_list *previous ;
};


num_list* push(num_list * head,unsigned data){
    num_list* node = (num_list *) malloc(sizeof(num_list));
    if (node ==NULL)
    {
        exit(1);
    }
    node->data = data;
    node->previous = head;
    return node;

}

num_list* pop(num_list *head){
    num_list* temp;
    temp=head;
    head=head->previous;
    free(temp);
    return head;
}

void print_minmum_element(num_list* head ){
    num_list * temp = head;
    unsigned t=head->data;
    
while (1)
    {
        if (temp==NULL)
            {
                printf("%d\n",t);
                break;
            }
        t= (t < (temp->data))? t :(temp->data);
        temp=temp->previous;
    }
}


int main (){

num_list * head=NULL;
//head = NULL;
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
                head = push(head,t);
    }
    else if (flag==2)
    {
        if(!head)
                {
                    //exit(1);
                    continue;
                }
                else 
                head = pop(head);
    }
    else if (flag==3)
    {
        if (!head)
            {
                printf("Empty\n");
            }
            else
                print_minmum_element(head);
    }
    else 
    //exit(1);
    continue;
}

return 0;
}