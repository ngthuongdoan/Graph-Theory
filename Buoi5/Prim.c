#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAXN 100
#define MAXLENGTH 100
#define INFINITY 999999
#define NOEDGE 0

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
typedef struct
{
    int n;
    int A[MAXN][MAXN];
    int w[MAXN][MAXN];
} Graph;

void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
    G->w[i][j] = 0;
}

void add_edge(Graph *G, int x, int y, int w)
{
    G->A[x][y] = 1;
    // G->A[y][x] = 1;
    G->w[x][y] = w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

int Prim(Graph *G, Graph *T)
{
    init_graph(T, G->n);
    int i, u, v;
    for (i = 1; i <= G->n; i++)
    {
        pi[i] = INFINITY;
        mark[i] = 0;
    }

    pi[1] = 0;
    mark[1] = 1;
    for (v = 1; v <= G->n; v++)
        if (G->w[1][v] != NOEDGE)
        {
            pi[v] = G->w[1][v];
            p[v] = 1;
        }

    int sum = 0;
    for (i = 1; i < G->n; i++)
    {
        int min_dist = INFINITY, min_u;
        for (u = 1; u <= G->n; u++)
            if (mark[u] == 0)

                if (min_dist > pi[u])
                {
                    min_dist = pi[u];
                    min_u = u;
                }
        u = min_u;
        mark[u] = 1;

        add_edge(T, p[min_u], min_u, min_dist);
        sum += min_dist;

        for (v = 1; v <= G->n; v++)
            if (G->A[u][v] != NOEDGE && mark[v] == 0)
                if (pi[v] > G->w[u][v])
                {
                    pi[v] = G->w[u][v];
                    p[v] = u;
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

    int weight = Prim(&G, &T);
    printf("%d\n", weight);
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (T.A[i][j] != 0)
                if (i < j)
                {
                    printf("%d %d %d\n", i, j, T.w[i][j]);
                }
                else
                {
                    printf("%d %d %d\n", j, i, T.w[i][j]);
                }

    return 0;
}
