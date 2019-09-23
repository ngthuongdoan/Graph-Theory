#include <stdio.h>
#include "DothiTrongSo.c"
#define INFINITY 9999999

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
        {
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j;
            }
        }
    
        mark[i] = 1;

        for (j = 1; j <= G->n; j++)
        {
            if (G->L[i][j] != NO_EDGE && mark[j] == 0)
            {
                if (pi[i] + G->L[i][j] < pi[j])
                {
                    pi[j] = pi[i] + G->L[i][j];
                    pi[j] = i;
                }
            }
        }
    }
}

void show(Graph G)
{
    int i;
    for (i = 1; i <= G.n; i++)
    {
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    }
}

void distantFromTo(Graph G, int u)
{
    int path[MAXN];
    int k = 0;
    int current = u;
    while (current != -1)
    {
        path[k] = current;
        k++;
        current = p[current];
    }

    int i;

    for (i = k - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
}