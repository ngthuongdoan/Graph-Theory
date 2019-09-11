#include "../Buoi 1/Queue.c"
#include "../Buoi 1/MaTranDinhDinh.c"

/* Duyệt đồ thị theo chiều rộng */
void breath_first_search(Graph *G)
{
    Queue L;
    int mark[MAX_VERTICES];
    MakeNull_Queue(&L);
    /* Khởi tạo mark, chưa đỉnh nào được xét */
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    /* Đưa 1 vào frontier */
    push(&L, 1);
    /* Duyệt 1 */
    mark[1] = 1;
    /* Vòng lặp chính dùng để duyệt */
    while (!Empty_Queue(L))
    {
        /* Lấy phần tử đầu tiên trong L ra */
        int x = top(&L);
        pop(&L);
        printf("Duyet %d\n",x);
        /* Lấy các đỉnh kề của nó */
        List list;
        list = neighbors(G, x);
        /* Xét các đỉnh kề của nó */
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(&list, j);
            if (mark[y] == 0)
            { // y chưa duyệt, duyệt nó
                printf("Duyet %d\n", y);
                mark[y] = 1; //Đánh dấu y đã duyệt
                push(&L, y); //Đưa vào hàng đợi để lát nữa xét
            }
        }
    }
}