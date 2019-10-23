#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGE 100

typedef struct
{
    int u, v, w;
} Edge;

typedef struct
{
    int n, m;
    Edge edge[MAX_EDGE];
} Graph;

int parent[MAX_EDGE];

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w)
{
    G->edge[G->m].u = u;
    G->edge[G->m].v = v;
    G->edge[G->m].w = w;
    G->m++;
}

void swap(Edge *e1, Edge *e2)
{
    Edge temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void arrange(Graph *G)
{
    int i, j;
    for (i = 0; i < (G->m - 1); i++)
        for (j = i + 1; j < G->m; j++)
            if (G->edge[i].w > G->edge[j].w)
                swap(&G->edge[i], &G->edge[j]);
}

void printMatrix(Graph G)
{
    int i, j;
    for (i = 0; i < G.m; i++)
    {
        printf("Edge[%d,%d] = %d\n", G.edge[i].u, G.edge[i].v, G.edge[i].w);
    }
}

int findRoot(int x)
{
    if (parent[x] = x)
        return x;
    return findRoot(parent[x]);
}

void Kruskal(Graph *G, Graph *T)
{
    int e, u;
    arrange(G);
    init_graph(T, G->n);
    for (u = 1; u <= G->n; u++)
        parent[u] = u;
    int sum_w = 0;
    for (e = 1; e <= G->m; e++)
    {
        int u = G->edge[e].u;
        int v = G->edge[e].v;
        int w = G->edge[e].w;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u != root_v)
        {
            add_edge(T, u, v, w);
            parent[root_v] = root_u;
            sum_w += w;
        }
    }
    printf("%d", sum_w);
}

int main(int argc, char const *argv[])
{
    Graph G, T;
    freopen("dt.txt", "r", stdin);
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int i;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
     printMatrix(G);
     arrange(&G);
     printf("\n");
     printMatrix(G);
     printf("\n");
//    Kruskal(&G,&T);

    return 0;
}
