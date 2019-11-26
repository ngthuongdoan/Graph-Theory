#include "../Buoi1/MaTranDinhDinh.c"
#define MAXVERTEXES 100
#define MAX_ELEMENTS 100

typedef struct
{
    int data[MAX_ELEMENTS];
    int front, rear;
} Queue;
void make_null_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}
int top(Queue *Q)
{
    return Q->data[Q->front];
}
void pop(Queue *Q)
{
    Q->front++;
}
int empty(Queue *Q)
{
    return Q->front > Q->rear;
}

void bfs(Graph G)
{
    Queue frontier;
    int mark[MAXVERTEXES];
    make_null_queue(&frontier);
    /* Khởi tạo mark, chưa đỉnh nào được xét */
    int j;
    for (j = 1; j <= G.n; j++)
        mark[j] = 0;
    /* Đưa 1 vào frontier */
    push(&frontier, 1);
    /* Duyệt 1 */
    printf("1\n");
    mark[1] = 1;
    /* Vòng lặp chính dùng để duyệt */
    while (!empty(&frontier))
    {
        /* Lấy phần tử đầu tiên trong L ra */
        int x = top(&frontier);
        pop(&frontier);
        /* Lấy các đỉnh kề của nó */
        List list = neighbors(G, x);
        /* Xét các đỉnh kề của nó */
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(list, j);
            if (mark[y] == 0)
            { // y chưa duyệt, duyệt nó
                printf("%d\n", y);
                mark[y] = 1;        //Đánh dấu y đã duyệt
                push(&frontier, y); //Đưa vào hàng đợi để lát nữa xét
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph G;
    freopen("dt.txt", "r", stdin);
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int i;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    bfs(G);
    return 0;
}
