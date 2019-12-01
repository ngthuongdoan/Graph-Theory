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

int parent[MAXN];

int findRoot(int u)
{
    return (parent[u] == u) ? u : findRoot(parent[u]);
}
void swap(Edge *e1, Edge *e2)
{
    Edge temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int Kruskal(Graph *G, Graph *T)
{
    //Edges Sort
    int i, j;
    for (i = 0; i <= G->m - 1; i++)
        for (j = i + 1; j <= G->m - 1; j++)
            if (G->edges[i].w > G->edges[j].w)
                swap(&(G->edges[i]), &(G->edges[j]));
    //Kruskal
    init_graph(T, G->n);
    int u;
    for (u = 1; u <= G->n; u++)
        parent[u] = u;

    int sum = 0;
    int e;
    for (e = 0; e <= (G->m - 1); e++)
    {
        int u = G->edges[e].x;
        int v = G->edges[e].y;
        int w = G->edges[e].w;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u != root_v)
        {
            add_edge(T, u, v, w);
            parent[root_v] = root_u;
            sum += w;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    Graph G, T;
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.

    int n, m, u, v, e, w;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    int weight = Kruskal(&G, &T);
    printf("%d\n", weight);
    int i;
    for (i = 0; i < T.m; i++)
    {
        if (T.edges[i].x < T.edges[i].y)
        {
            printf("%d %d %d\n", T.edges[i].x, T.edges[i].y, T.edges[i].w);
        }
        else
        {
            printf("%d %d %d\n", T.edges[i].y, T.edges[i].x, T.edges[i].w);
        }
    }

    return 0;
}
