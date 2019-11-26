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

typedef struct
{
    int n, m;
    int A[MAXN][MAXN];
} Graph;

void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

List neighbor(Graph *G, int x)
{
    int i;
    List list;
    makenull_list(&list);
    for (i = 1; i <= G->n; i++)
        if (G->A[x][i] != 0)
            addlist(&list, i);
    return list;
}

int mark[MAXELEMENT];

void visit(Graph *G, int u)
{
    if (mark[u] == 1)
        return;
    printf("%d\n", u);
    mark[u] = 1;
    List list = neighbor(G, u);
    int i;
    for (i = 1; i <= list.idx; i++)
        visit(G, elementAt(&list, i));
}

void dfs_dequy(Graph *G)
{
    int i;
    for (i = 0; i < G->n; i++)
        mark[i] = 0;
    for (i = 1; i <= G->n; i++)
        if (mark[i] == 0)
            visit(G, i);
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

    dfs_dequy(&G);
    return 0;
}
