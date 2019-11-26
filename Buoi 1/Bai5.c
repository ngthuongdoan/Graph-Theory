#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100

typedef struct
{
    int x, y;
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

void add_edge(Graph *G, int x, int y)
{
    G->edges[G->m].x = x;
    G->edges[G->m].y = y;
    G->m += 1;
}

int main(int argc, char const *argv[])
{
    Graph G;
    init_graph(&G, 4);
    add_edge(&G, 1, 3);
    printf('%d', G.edges[0].x);
    return 0;
}
