//Declaration
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICLES 100
#define MAXLENGTH 100
#define INFINITY 9999999
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
    int w[MAXVERTICLES][MAXVERTICLES];
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

void delete_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 0;
    G->A[y][x] = 0;
    G->w[x][y] = 0;
    G->w[y][x] = 0;
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

void printWeightMatrix(Graph G, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", G.w[i][j]);
        }
        printf("\n");
    }
}

#define MAXN 100
#define NO_EDGE 0
int pi[MAXN][MAXN];
int next[MAXN][MAXN];

void Floyd_Warshall(Graph *G)
{
    int u, v, k;
    for (u = 1; u <= G->n; u++)
        for (v = 1; v <= G->n; v++)
        {
            pi[u][v] = INFINITY;
            next[u][v] = -1;
        }

    for (u = 1; u <= G->n; u++)
        pi[u][u] = 0;

    for (u = 1; u <= G->n; u++)
        for (v = 1; v <= G->n; v++)
            if (G->w[u][v] != NO_EDGE)
            {
                pi[u][v] = G->w[u][v];
                next[u][v] = v;
            }

    for (k = 1; k <= G->n; k++)
        for (u = 1; u <= G->n; u++)
            for (v = 1; v <= G->n; v++)
                if (pi[u][k] != INFINITY && pi[k][v] != INFINITY)
                    if (pi[u][k] + pi[k][v] < pi[u][v])
                    {
                        pi[u][v] = pi[u][k] + pi[k][v];
                        next[u][v] = next[u][k];
                    }
}

int main(int argc, char const *argv[])
{
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    // printmatrix(G, n);
    // printf("\n\n");
    // printWeightMatrix(G, n);
    Floyd_Warshall(&G);
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (pi[i][j] == INFINITY)
            {
                printf("%d -> %d: oo\n", i, j);
            }
            else
            {
                printf("%d -> %d: %d\n", i, j, pi[i][j]);
            }

    return 0;
}
