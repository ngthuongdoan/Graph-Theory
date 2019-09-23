#define MAXN 1000
#define NO_EDGE 0

typedef struct
{
    int n;
    int L[MAXN][MAXN];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i < -n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            G->L[i][j] = NO_EDGE;
        }
    }
}

void add_edge(Graph *G, int x, int y, int w)
{
    G->L[x][y] = w;
}
