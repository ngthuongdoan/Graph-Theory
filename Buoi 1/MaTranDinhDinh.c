#include <stdio.h>
#include <stdlib.h>
#include "List.c"
#define MAX_VERTICES 100

typedef struct
{
    // n la so dinh
    int n;
    // ma tran dinh cung
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

// ham khoi tao do thi
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}

// them cung vao do thi
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

//Tinh bac cua mot dinh đơn cung
int degree(Graph *G, int x)
{
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        if (G->A[x][y] > 0)
            deg++;
    return deg;
}
//Tinh bac cua mot dinh đa cung
// int degree(Graph *G, int x)
// {
//     int y, deg = 0;
//     for (y = 1; y <= G->n; y++)
//         deg+= G->A[x][y];
//     return deg;
// }

List neighbors(Graph *G, int x)
{
    List L;
    make_null(&L);
    int y;
    for (y = 1; y <= G->n; y++)
    {
        if (adjacent(G, x, y))
            push_back(&L, y);
    }
    return L;
}

void inDS(Graph *G)
{
    int i, j;
    for (i = 0; i < G->n; i++)
    {
        for (j = 0; j < G->n; j++)
        {
            printf("%d ", G->A[i][j]);
        }
        printf("\n");
    }
}
// int main(int argc, char const *argv[])
// {
//     Graph G;
//     int n = 4, v;
//     init_graph(&G, n);
//     add_edge(&G, 1, 2);
//     add_edge(&G, 1, 3);
//     add_edge(&G, 1, 3);
//     add_edge(&G, 3, 4);
//     add_edge(&G, 1, 4);

//     for (v = 1; v <= n; v++)
//     {
//         printf("deg(%d) = %d\n", v, degree(&G, v));
//     }
    
//     return 0;
// }
