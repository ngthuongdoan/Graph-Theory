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

ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}

void copylist(List *L1, List *L2)
{
    List temp = *L2;
    *L2 = *L1;
    *L1 = temp;
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
}

//-----------------------EndGraph-----------------------------//

int rank[MAXVERTICLES];
int k = 0;
void ranking(Graph *G)
{
    int d[MAXVERTICLES];
    int x, u;
    for (u = 1; u <= G->n; u++)
    {
        d[u] = 0;
        rank[u] = 0;
    }

    for (x = 1; x <= G->n; x++)
        for (u = 1; u <= G->n; u++)
            if (G->A[x][u] != 0)
                d[u]++;

    List S1, S2;
    makenullList(&S1);

    for (u = 1; u <= G->n; u++)
        if (d[u] == 0)
            pushback(&S1, u);
    int i;
    while (S1.size > 0)
    {
        makenullList(&S2);
        for (i = 1; i <= S1.size; i++)
        {
            int u = element_at(&S1, i);
            rank[u] = k;
            int v;
            for (v = 1; v <= G->n; v++)
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (d[v] == 0)
                        pushback(&S2, v);
                }
        }
        copylist(&S1, &S2);
        k++;
    }
}

void topo_sort(Graph *G, List *L)
{
    ranking(G);
    makenullList(L);
    int i, j;
    for (i = 0; i <= k; i++)
        for (j = 1; j <= G->n; j++)
            if (rank[j] == i)
                pushback(L, j);
}

int main(int argc, char const *argv[])
{
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    int i;
    List L;
    topo_sort(&G, &L);
    for (i = 1; i <= n; i++)
        printf("%d\n", rank[i]);

    for (i = 1; i <= L.size; i++)
        printf("%d ", element_at(&L, i));

    return 0;
}
