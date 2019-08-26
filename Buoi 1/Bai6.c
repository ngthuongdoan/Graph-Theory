#include "MaTranDinhDinh.c"

int main(int argc, char const *argv[])
{
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    // int i, j, A[n][n];
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //         if (adjacent(&G, i, j))
    //         {
    //             A[i][j] = 1;
    //         }
    //         else
    //         {
    //             A[i][j] = 0;
    //         }
    // }

    inDS(&G);
    return 0;
}
