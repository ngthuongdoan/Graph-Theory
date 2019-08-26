#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGE 50

typedef struct
{
    // n la so dinh, m la so cung
    int n, m;
    // ma tran dinh cung
    int A[MAX_VERTICES][MAX_EDGE];
} Graph;

// ham khoi tao do thi
void init_graph(Graph *G, int n, int m)
{
    int i, j;
    G->n = n;
    G->m = m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            G->A[i][j] = 0;
}

int adjacent(Graph *G, int x, int y)
{
    int e;
    for (e = 1; e <= G->m; e++)
        if (G->A[x][e] == 1 && G->A[y][e] == 1)
            return 1;
    return 0;
}


// them cung vao do thi
void add_edge(Graph *G, int e, int x, int y)
{
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

//Tinh bac cua mot dinh
int degree(Graph *G, int x)
{
    int e, deg = 0;
    for (e = 1; e <= G->m; e++)
        if (G->A[x][e] == 1)
            deg++;
    return deg;
}

int main(int argc, char *argv[])
{
    Graph G;
    int n, m, u, v, e;
    if (argc < 2)
    {
        printf("Hay go: %s <ten-file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    fscanf(f, "%d%d", &n, &m);

    init_graph(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        fscanf(f, "%d%d", &u, &v);
        add_edge(&G, e, u, v);
    }

    for (v = 1; v <= n; v++)
    {
        printf("deg(%d) = %d\n", v, degree(&G, v));
    }
    return 0;
}
