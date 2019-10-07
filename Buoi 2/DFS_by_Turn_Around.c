#include "../Buoi 1/MaTranDinhDinh.c"

int mark[MAX_VERTICES];
void traversal(Graph *G, int x)
{
    if (mark[x] == 1)
        return;
    printf("Duyet %d\n", x);
    mark[x] = 1;

    List list = neighbors(G, x);
    int j;
    for (j = 1; j <= list.size; j++)
    {
        /* code */
        int y = element_at(&list, j);
        traversal(G, y);
    }
}

void DFS(Graph *G)
{
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    traversal(G, 1);
}