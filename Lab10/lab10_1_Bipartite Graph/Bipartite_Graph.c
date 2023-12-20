#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    unsigned data ;
    struct stack *previous ;
}stack;

void push(stack ** head,unsigned data){
    stack* node = (stack *) malloc(sizeof(stack));
    if (node ==NULL) exit(1);
    node->data = data;
    node->previous = *head;
    *head = node;
}

int pop(stack **head){
    stack* temp;
    int t = (*head)->data;
    temp=*head;
    *head=(*head)->previous;
    free(temp);
    return t;
}

int N;

unsigned is_bipartite(int g[][N],int src)
{
    int color_arr[N];
    for (int i = 0; i < N; ++i) color_arr[i]=-1 ;
    color_arr[src]=1;

    stack *head = NULL;
    push(&head,src);

    while (head)
    {
        int t = pop(&head);

        if (g[t][t]==1) return 0;//checks if cycled in the first v
        
        for (int i = 0; i < N; ++i)
        {
            if(g[t][i]&& color_arr[i]==-1)
            {
                color_arr[i]=1-color_arr[t];
                push(&head,i);
            }

            else if (g[t][i]&&color_arr[i]==color_arr[t]) 
                return 0;
        }
    }
    //if passed no cycles
    return 1;
}

int main (){
    int E ,t,t1; 
    scanf("%d",&N);
    scanf("%d",&E);
    int g[N][N] ;
for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        g[i][j]=0;

for (int i = 0; i < E; i++)
{
    scanf("%d %d",&t,&t1);
    g[t-1][t1-1]=1;
    g[t1-1][t-1]=1;
}

is_bipartite(g,0)?printf("Yes"):printf("No");
return 0;
}