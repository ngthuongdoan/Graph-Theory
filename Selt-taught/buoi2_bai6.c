#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define MAXM 100
#define MAXELEMENT 100

//List Structure
typedef struct
{
    int idx;
    int A[MAXELEMENT];
} List;

void makenull_list(List *l)
{
    l->idx = 0;
}

void addlist(List *l, int x)
{
    l->A[l->idx] = x;
    l->idx++;
}

int elementAt(List *l, int idx)
{
    return l->A[idx - 1];
}

int countlist(List *l)
{
    return l->idx;
}
//Graph Structure

typedef struct
{
    int x, y;
} Edge;

typedef struct
{
    int n, m;
    Edge edges[MAXM];
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

int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 0; i < G->m; i++)
        if ((G->edges[i].x == x) | (G->edges[i].y == x))
            deg++;
    return deg;
}

int parent[MAXELEMENT];

int findRoot(int u)
{
    while (u != parent[u])
        u = parent[u];
    return u;
}

int chutrinh(Graph *G)
{
    int i;
    for (i = 1; i <= G->n; i++)
        parent[i] = i;
    for (i = 0; i < G->m; i++)
    {
        int r_u = findRoot(G->edges[i].x);
        int r_v = findRoot(G->edges[i].y);
        if (r_u != r_v)
        {
            parent[r_v] = r_u;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    Graph G;
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.

    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    List a, b;
    makenull_list(&a);
    makenull_list(&b);
    int check = chutrinh(&G);

    if (check == 0)
    {
        printf("IMPOSSIBLE");
    }
    else
    {
        int i, j, k;
        for (i = 1; i <= n; i++)
        {
            if (degree(&G, i) == 1)
            {
                addlist(&a, i);
            }
            else
            {
                addlist(&b, i);
            }
        }
        if (elementAt(&a, 1) < elementAt(&b, 1))
        {
            for (j = 1; j <= a.idx; j++)
            {
                printf("%d ", elementAt(&a, j));
            }
            printf("\n");
            for (k = 1; k <= b.idx; k++)
            {
                printf("%d ", elementAt(&b, k));
            }
        }
        else
        {
            for (k = 1; k <= b.idx; k++)
            {
                printf("%d ", elementAt(&b, k));
            }
            printf("\n");
            for (j = 1; j <= a.idx; j++)
            {
                printf("%d ", elementAt(&a, j));
            }
        }
    }

    return 0;
}