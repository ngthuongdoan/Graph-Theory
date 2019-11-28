#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAXN 100
#define INFINITY 9999999

typedef struct
{
    int x, y;
    int w;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int x, int y, int w)
{
    G->edges[G->m].x = x;
    G->edges[G->m].y = y;
    G->edges[G->m].w = w;
    G->m++;
}

int pi[MAXN];
int p[MAXN];

void BellmaFord(Graph *G, int s)
{
    int j, it;
    int i;
    for (i = 1; i <= G->n; i++)
        pi[i] = INFINITY;
    pi[s] = 0;
    p[s] = -1;

    for (it = 1; it < G->n; it++)
        for (j = 0; j < G->m; j++)
        {
            int x = G->edges[j].x;
            int y = G->edges[j].y;
            int w = G->edges[j].w;
            if (pi[x] + w < pi[y])
            {
                pi[y] = pi[x] + w;
                p[y] = x;
            }
        }
}

void checkChuTrinhAm(Graph *G, int s)
{
    BellmaFord(G, s);
    int j;
    for (j = 0; j < G->m; j++)
    {
        int x = G->edges[j].x;
        int y = G->edges[j].y;
        int w = G->edges[j].w;
        if (pi[x] + w < pi[y])
        {
            printf("YES");
            return;
        }
    }
    printf("NO");
}

int main(int argc, char const *argv[])
{
    Graph G;
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.

    int n, m, u, v, e, w;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 1; e <= m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int s;
    scanf("%d", &s);
    checkChuTrinhAm(&G, s);
    // BellmaFord(&G, 1);
    // int i;
    // for (i = 1; i <= n; i++)
    // {
    //     printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    // }

    return 0;
}
