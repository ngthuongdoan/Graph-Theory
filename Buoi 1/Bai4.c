#include "MaTranDinhDinh.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    int max = -1000, state;
    for (v = 1; v <= n; v++)
        if (degree(&G, v) > max){
            max = degree(&G, v);
            state=v;
        }
    printf("%d %d",state, max);
    return 0;
}
