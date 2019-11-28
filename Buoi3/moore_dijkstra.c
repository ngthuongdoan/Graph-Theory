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

//-----------------------EndGraph-----------------------------//

#define INFINITY 9999999
#define MAXN 9999999
#define NOEDGE 0
int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void Dijkstra(Graph *G, int s)
{
    int i, j, it;
    for (i = 1; i <= G->n; i++)
    {
        pi[i] = INFINITY;
        mark[i] = 0;
    }

    pi[s] = 0;
    p[s] = -1;

    for (it = 1; it < G->n; it++)
    {
        int min_pi = INFINITY;
        for (j = 1; j <= G->n; j++)
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j;
            }

        mark[i] = 1;
        for (j = 1; j <= G->n; j++)
            if (G->w[i][j] != NOEDGE && mark[j] == 0)
            {
                if (pi[i] + G->w[i][j] < pi[j])
                {
                    pi[j] = pi[i] + G->w[i][j];
                    p[j] = i;
                }
            }
    }
}

int fromStoT(Graph *G, int s, int t)
{
    // int current = s;
    // int count = 0;
    // while (p[current] != t)
    // {
    //     count += pi[current];
    //     current = p[current];
    // }
    // return count;
}

int main(int argc, char const *argv[])
{
    Graph G;
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
    int s, t;
    scanf("%d%d", &s, &t);
    // printf("%d %d\n", s, t);
    Dijkstra(&G, 1);
    // for (i = 1; i <= n; i++)
    // {
    //     printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    // }

    printf("%d", pi[t]+pi[s]);

    return 0;
}
