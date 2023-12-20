#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX], front = -1,rear = -1;
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();
int N;

int in_deg(int g[][N],int i)
{
    int in_d=0;
    for (int j = 0; j < N; j++)
    {
        if(g[j][i]==1)
            in_d++;
    }
    return in_d;
}

int out_deg(int g[][N],int i)
{
    int out_d=0;
    for (int j = 0; j < N; j++)
    {
        if(g[i][j]==1)
        out_d++;
    }
    return out_d;
}

int main()
{

    int   E ,t1,t2;
    scanf("%d",&N);
    int graph[N][N];
    scanf("%d",&E);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                //if(graph[i][j]!=1)
                graph[i][j] = 0 ;
            }
        }
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d",&t1,&t2);
            graph[t1-1][t2-1] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ",graph[i][j]); 
                          }
        printf("\n");
        }


int out_degr[N],in_degr[N];
int count = 0 ,  topo[N+1],v;

for (int i = 0; i < N; i++)
{
    out_degr[i]=out_deg(graph,i);
    in_degr[i]=in_deg(graph,i);
    if( out_degr[i]== 0 )
    {
        insert_queue(i);
    //topo[++count] = i;
    }
    
    
}
while(  !isEmpty_queue( ) && count < N )
        {
                v = delete_queue();
        topo[++count] = v; /*Add vertex v to topo_order array*/
                /*Delete all edges going fron vertex v */
                for(int i=0; i<N; i++)
                {
                        if(graph[i][v] == 1)
                        {
                                graph[i][v] = 0;
                                out_degr[i] = out_degr[i]-1;
                                if(out_degr[i] == 0)
                                        insert_queue(i);
                        }
                }
        }

for (int i = 0; i < N; i++)
{
    printf(" in_d %d  out_d %d ,",in_degr[i],out_degr[i]);
}
         printf("\nVertices in topological order are :\n");

 for(int i=1; i<=count; i++)
                printf( "%d ",topo[i] );
        printf("\n");




}

void insert_queue(int vertex)
{
        if (rear == MAX-1)
                printf("\nQueue Overflow\n");
        else
        {
                if (front == -1)  /*If queue is initially empty */
                        front = 0;
                rear = rear+1;
                queue[rear] = vertex ;
        }
}/*End of insert_queue()*/

int isEmpty_queue()
{
        if(front == -1 || front > rear )
                return 1;
        else
                return 0;
}/*End of isEmpty_queue()*/

int delete_queue()
{
        int del_item;
        if (front == -1 || front > rear)
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        else
        {
                del_item = queue[front];
                front = front+1;
                return del_item;
        }
}/*End of delete_queue() */
