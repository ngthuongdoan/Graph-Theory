typedef struct
{
    int x, y;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[100];
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int x, int y)
{
    int i;
    for (i = 1; i <= G->m; i++)
    {
        G->edges->x = x;
        G->edges->y = y;
    }
}
