#include "../Buoi1/MaTranDinhDinh.c"
#define MAXLENGTH 100
#define MAXVERTEXES 100
//-------Stack---------//
typedef int ElementType;
typedef struct
{
    int data[MAXLENGTH];
    int size;
} Stack;

void makenullStack(Stack *S)
{
    S->size = 0;
}

ElementType top(Stack S)
{
    return S.data[S.size - 1];
}

void pop(Stack *S)
{
    S->size--;
}

int empty(Stack S)
{
    return S.size == 0;
}

void push(Stack *S, ElementType x)
{
    S->data[S->size] = x;
    S->size++;
}
//-------EndStack------//
void dfs(Graph G)
{
    Stack S;
    int mark[MAXVERTEXES];
    makenullStack(&S);
    /* Khởi tạo mark, chưa đỉnh nào được duyệt */
    int j;
    for (j = 1; j <= G.n; j++)
        mark[j] = 0;
    /* Đưa 1 vào L, bắt đầu duyệt từ đỉnh 1 */
    push(&S, 1);
    /* Vòng lặp chính dùng để duyệt */
    while (!empty(S))
    {
        /* Lấy phần tử đầu tiên trong L ra */
        int x = top(S);
        pop(&S);
        if (mark[x] != 0) // Đã duyệt rồi, bỏ qua
            continue;
        printf("%d\n", x);
        mark[x] = 1; //Đánh dấu nó đã duyệt
        /* Lấy các đỉnh kề của nó */
        List list = neighbors(G, x);
        /* Xét các đỉnh kề của nó */
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(list, j);
            push(&S, y);
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
    dfs(G);
    return 0;
}
