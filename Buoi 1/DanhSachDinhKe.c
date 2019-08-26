#include <stdio.h>
#include <stdlib.h>
#include "List.c"
#define MAX_VERTICES 100

typedef struct
{
    // n la so dinh
    int n;
    // ma tran dinh cung
    List adj[MAX_VERTICES];
} Graph;

// ham khoi tao do thi
void init_graph(Graph *G, int n, int m)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        make_null(&G->adj[i]);
}

int adjacent(Graph *G, int x, int y)
{
    int j;
    for (j = 1; j <= G->adj[x].size; j++)
        if (element_at(&G->adj[x], j) == y)
            return 1;
    return 0;
}

// them cung vao do thi
void add_edge(Graph *G, int x, int y)
{
    push_back(&G->adj[x], y);
    push_back(&G->adj[y], x);
}

//Tinh bac cua mot dinh đơn cung
int degree(Graph *G, int x)
{
    return G->adj[x].size;
}

void inDS(Graph *G)
{
    int i;
    for (int i = 0; i < G->n; i++)
        printf("%d",G->adj[i]);
    printf("\n");
}
//------------Duyet do thi--------------
//Duyet chieu sau
// void depth_first_search(Graph* G){
//     Stack S;
// }