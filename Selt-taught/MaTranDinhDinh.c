//Declaration
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICLES 100
#define MAXLENGTH 100

//-----------------------List---------------------------//
typedef int ElementType;
typedef struct
{
    ElementType data[MAXLENGTH];
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
    makenullList(L2);
    int i;
    for (i = 1; i <= L1->size; i++)
        pushback(L2, element_at(*L1, i));
}
//-----------------------EndList-----------------------------//
//-----------------------Graph-----------------------------//
typedef struct
{
    int n;
    int A[MAXVERTICLES][MAXVERTICLES];
} Graph;

void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

void delete_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 0;
    G->A[y][x] = 0;
}

int adjacent(Graph G, int x, int y)
{
    if (G.A[x][y] == 1)
        return 1;
    return 0;
}

List neighbors(Graph G, int x)
{
    List L;
    makenullList(&L);
    int i;
    for (i = 1; i <= G.n; i++)
        if (adjacent(G, x, i) == 1)
            pushback(&L, i);
    return L;
}

int degree(Graph G, int x)
{
    int deg = 0;
    int i;
    for (i = 1; i <= G.n; i++)
        if (G.A[x][i] != 0)
            deg += G.A[x][i];
    return deg;
}

void printmatrix(Graph G, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}
//-----------------------EndGraph-----------------------------//