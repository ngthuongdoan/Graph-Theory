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

#define INFINITY 9999999
int d[MAXVERTICLES];
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

int max(int x, int y)
{
    return (x >= y) ? x : y;
}

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int main()
{
    Graph G;
    int n, u, x, v, j, z, y;
    //Doc do thi
    freopen("dt.txt", "r", stdin);
    scanf("%d", &n);
    init_graph(&G, n + 2);
    d[n + 1] = 0;

    for (u = 1; u <= n; u++)
    {
        scanf("%d", &d[u]);
        do
        {
            scanf("%d", &x);
            if (x > 0)
                add_edge(&G, x, u);
        } while (x > 0);
    }
    // scanf("%d%d", &z, &y);

    for (u = 1; u <= n; u++)
    {
        int deg_neg = 0;
        for (x = 1; x <= n; x++)
            if (G.A[x][u] > 0)
                deg_neg++;
        if (deg_neg == 0)
            add_edge(&G, n + 1, u);
    }

    for (u = 1; u <= n; u++)
    {
        int deg_pos = 0;
        for (x = 1; x <= n; x++)
            if (G.A[u][x] > 0)
                deg_pos++;
        if (deg_pos == 0)
            add_edge(&G, u, n + 2);
    }
    List L;
    int i;
    topo_sort(&G, &L);

    int t[MAXVERTICLES];
    t[n + 1] = 0;

    for (i = 2; i <= L.size; i++)
    {
        int u = element_at(&L, i);
        t[u] = -1;
        for (x = 1; x <= G.n; x++)
            if (G.A[x][u] > 0)
                t[u] = max(t[u], t[x] + d[x]);
    }

    int T[MAXVERTICLES];
    T[n + 2] = t[n + 2];
    for (i = L.size - 1; i >= 1; i--)
    {
        int u = element_at(&L, i);
        T[u] = INFINITY;
        for (x = 1; x <= G.n; x++)
            if (G.A[u][x] > 0)
                T[u] = min(T[u], T[x] - d[u]);
    }

    for (i = 1; i <= L.size; i++)
        printf("%d ", element_at(&L, i));
    printf("\n");

    for (i = 1; i <= n+2; i++)
        if (t[i] == T[i])
            printf("%d\n", i);
}