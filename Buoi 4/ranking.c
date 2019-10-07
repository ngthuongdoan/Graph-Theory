#include "E:\Code\Graph Theory\Graph-Theory\Buoi 1\List.c"
#define MAX_VERTICES 100

typedef struct
{
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

int rank[MAX_VERTICES];
void ranking(Graph *G)
{
    int d[MAX_VERTICES];
    int x, u;
    for (u = 1; u <= G->n; u++)
        d[u] = 0;

    for (x = 1; x < G->n; x++)
        for (u = 1; u <= G->n; u++)
            if (G->A[x][u] != 0)
                d[u]++;

    List S1, S2;
    make_null(&S1);
    for (u = 1; u <= G->n; u++)
        if (d[u] == 0)
            push_back(&S1, u);

    int k = 1, i;
    while (S1.size > 0)
    {
        make_null(&S2);
        for (i = 1; i <= S1.size; i++)
        {
            /* code */
            int u = element_at(&S1, i);
            rank[u] = k;
            int v;
            for (v = 1; v <= G->n; v++)
            {
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (d[v] == 0)
                        push_back(&S2, v);
                }
            }
            copy_list(&S1, &S2);
            k++;
        }
    }
}