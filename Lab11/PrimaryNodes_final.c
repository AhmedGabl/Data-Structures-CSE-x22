#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, N;

void enqueue(int queue[], int v)
{
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = v;
}

int is_empty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int dequeue(int queue[])
{
    int del_item;
    if (front == -1 || front > rear)
        exit(0);
    else
    {
        del_item = queue[front];
        front = front + 1;
        return del_item;
    }
}

int out_deg(int g[][N], int i)
{
    int out_d = 0;
    for (int j = 0; j < N; j++)
    {
        if (g[i][j] == 1)
            out_d++;
    }
    return out_d;
}

int main()
{
    int i, E, t1, t2;
    scanf("%d", &N);
    int queue[N];
    int graph[N][N];
    scanf("%d", &E);
    for (i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &t1, &t2);
        graph[t1 - 1][t2 - 1] = 1;
    }

    int out_degr[N];
    int count = 0, topo[N], v;

    for (i = 0; i < N; i++)
    {
        out_degr[i] = out_deg(graph, i);
        if (out_degr[i] == 0)
            enqueue(queue, i);
    }

    // topological sorting thegraph for out deg = 0 so all if it's cycle or not primary wont be 0
    while (!is_empty() && count < N)
    {
        v = dequeue(queue);
        topo[count] = v;
        count++; // Add v to topo array
        // Delete all edges going to v
        for (i = 0; i < N; i++)
        {
            if (graph[i][v] == 1)
            {
                graph[i][v] = 0;
                out_degr[i] = out_degr[i] - 1;
                if (out_degr[i] == 0)
                    enqueue(queue, i);
            }
        }
    }

    if (count > 0)
    {
        for (i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (topo[i] > topo[j])
                {
                    t1 = topo[i];
                    topo[i] = topo[j];
                    topo[j] = t1;
                }
            }
        }
        for (i = 0; i < count; i++)
            printf("%d\n", topo[i]+1);
    }
    else
        printf("-1");
}
