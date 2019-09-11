#include "../Buoi 1/Stack.c"
#include "../Buoi 1/MaTranDinhDinh.c"

/* Duyet do thi theo chieu sau */
void depth_first_search(Graph *G)
{
    Stack Frontier;
    int mark[MAX_VERTICES];
    MakeNull_Stack(&Frontier);
    /* Khởi tạo mark, chưa đỉnh nào được duyệt */
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    /* Đưa 1 vào L, bắt đầu duyệt từ đỉnh 1 */
    Push(1, &Frontier);
    mark[1] = 1;
    /* Vòng lặp chính dùng để duyệt */
    while (!Empty_Stack(&Frontier))
    {
        /* Lấy phần tử đầu tiên trong L ra */
        int x = Top(Frontier);
        Pop(&Frontier);
        printf("Duyet %d\n", x);
        List list = neighbors(G, x);
        /* Xét các đỉnh kề của nó */
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(&list, j);
            if (mark[y] == 0)
            {
                mark[y] == 1;
                Push(y, &Frontier);
            }
        }
    }
}