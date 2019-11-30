#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define NO_EDGE 0
#define INF 9999999
#define MAX_ELEMENTS 100

typedef struct
{
    int data[MAX_ELEMENTS];
    int front, rear;
} Queue;
void make_null_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}
int top(Queue *Q)
{
    return Q->data[Q->front];
}
void pop(Queue *Q)
{
    Q->front++;
}
int empty(Queue *Q)
{
    return Q->front > Q->rear;
}
//------------------------------------------
typedef struct
{
    int C[MAXN][MAXN];
    int F[MAXN][MAXN];
    int n;
} Graph;

typedef struct
{
    int dir;
    int pre;
    int sigma;
} Label;
Label labels[MAXN];

void init_graph(Graph *G, int n)
{
    G->n = n;
}
void init_flow(Graph *G)
{
    int u, v;
    for (u = 1; u <= G->n; u++)
        for (v = 1; v <= G->n; v++)
            G->F[u][v] = 0;
}

void add_edge(Graph *G, int x, int y, int w)
{
    G->C[x][y] = w;
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int FordFullkerson(Graph *G, int s, int t)
{
    init_flow(G);
    Queue Q;
    int sum_flow = 0;
    do
    {
        int u;
        for (u = 1; u <= G->n; u++)
            labels[u].dir = 0;

        labels[s].dir = +1;
        labels[s].pre = s;
        labels[s].sigma = INF;
        make_null_queue(&Q);
        push(&Q, s);

        int found = 0;
        while (!empty(&Q))
        {
            int x = top(&Q);
            pop(&Q);
            int v;
            for (v = 1; v <= G->n; v++)
            {
                if (labels[v].dir == 0 && G->C[x][v] != NO_EDGE && G->F[x][v] < G->C[x][v])
                {
                    labels[v].dir = +1;
                    labels[v].pre = x;
                    labels[v].sigma = min(labels[x].sigma, G->C[x][v] - G->F[x][v]);
                    push(&Q, v);
                }

                if (labels[v].dir == 0 && G->C[x][v] != NO_EDGE && G->F[x][v] > 0)
                {
                    labels[v].dir = -1;
                    labels[v].pre = x;
                    labels[v].sigma = min(labels[x].sigma, G->F[x][v]);
                    push(&Q, v);
                }
            }
            if (labels[t].dir != 0)
            {
                found = 1;
                break;
            }
        }
        

        if (found == 1)
        {
            int x = t;
            int sigma = labels[t].sigma;
            sum_flow += sigma;

            while (x != s)
            {
                int u = labels[x].pre;
                if (labels[x].dir > 0)
                {
                    G->F[u][x] += sigma;
                }
                else
                {
                    G->F[x][u] -= sigma;
                }
                x = u;
            }
            // break;
        }
        else
        {
            break;
        }
    } while (1);
    return sum_flow;
}

int main(int argc, char const *argv[])
{
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    int flow = FordFullkerson(&G, 1, n);
    printf("%d", flow);
    return 0;
}
