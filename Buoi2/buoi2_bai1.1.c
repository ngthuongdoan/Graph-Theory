#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define MAXM 100
#define MAXELEMENT 100

//Queue Structure
typedef struct
{
    int front, rear;
    int A[MAXELEMENT];
} Queue;

void makenull_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue *Q, int x)
{
    Q->rear++;
    Q->A[Q->rear] = x;
}

void pop(Queue *Q)
{
    Q->front++;
}

int empty(Queue *Q)
{
    return Q->front > Q->rear;
}

int top(Queue *Q)
{
    return Q->A[Q->front];
}

//List Structure
// typedef struct
// {
//     int idx;
//     int A[MAXELEMENT];
// } List;

// void makenull_list(List *l)
// {
//     l->idx = 0;
// }

// void addlist(List *l, int x)
// {
//     l->A[l->idx] = x;
//     l->idx++;
// }

// int elementAt(List *l, int idx)
// {
//     return l->A[idx - 1];
// }

// int countlist(List *l)
// {
//     return l->idx;
// }
typedef int ElementType;
typedef struct
{
    ElementType data[MAXN];
    int size;
} List;

void makenullList(List *L)
{
    L->size = 0;
}

void pushback(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}

ElementType element_at(List L, int i)
{
    return L.data[i - 1];
}

int countlist(List L)
{
    return L.size;
}

void copylist(List *L1, List *L2)
{
    List temp = *L2;
    *L2 = *L1;
    *L1 = temp;
}


//Graph Structure
typedef struct
{
    int n, m;
    int A[MAXN][MAXN];
} Graph;

void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

List neighbor(Graph *G, int x)
{
    int i;
    List list;
    makenullList(&list);
    for (i = 1; i <= G->n; i++)
        if (G->A[x][i] != 0)
            pushback(&list, i);
    return list;
}

void bfs(Graph *G)
{
    Queue q;
    makenull_queue(&q);
    int mark[MAXN];
    int i;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    for (i = 1; i <= G->n; i++)
        if (mark[i] == 0)
        {
            mark[i] = 1;
            push(&q, i);
            printf("%d\n", i);
            while (!empty(&q))
            {
                int i;
                int u = top(&q);
                pop(&q);
                List list = neighbor(G, u);
                for (i = 1; i <= list.size; i++)
                    if (mark[element_at(list, i)] == 0)
                    {
                        printf("%d\n",
                               element_at(list, i));
                        mark[element_at(list, i)] = 1;
                        push(&q, element_at(list, i));
                    }
            }
        }
}

//BFS
// void bfs(Graph *G)
// {
//     Queue q;
//     makenull_queue(&q);
//     int mark[MAXN];
//     int i;
//     for (i = 1; i <= G->n; i++)
//         mark[i] = 0;
//     for (i = 1; i <= G->n; i++)
//         if (mark[i] == 0)
//         {
//             mark[i]=1;
//             enqueue(&q,i);
//             printf("%d\n",i);
//             while (!empty(&q))
//             {
//                 int i;
//                 int u = top(&q);
//                 dequeue(&q);
//                 List list = neighbor(G, u);
//                 for (i = 1; i <= list.idx; i++)
//                     if (mark[elementAt(&list, i)] == 0)
//                     {
//                         printf("%d\n", elementAt(&list, i));
//                         mark[elementAt(&list, i)] = 1;
//                         enqueue(&q, elementAt(&list, i));
//                     }
//             }
//         }
// }

int main(int argc, char const *argv[])
{
    Graph G;
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.

    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    bfs(&G);
    return 0;
}
