void depth_first_search(Graph *G)
{
    Stack L;
    int mark[MAX_VERTEXES];
    make_null_stack(&L);
    /* Kh?i t?o mark, chua d?nh nào du?c duy?t */
    int j, temp;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    /* Ðua 1 vào L, b?t d?u duy?t t? d?nh 1 */
    for (temp = 1; temp <= G->n; temp++)
        if (mark[temp] == 0)
        {
            push(&L, temp);
            /* Vòng l?p chính dùng d? duy?t */
            while (!empty(&L))
            {
                /* L?y ph?n t? d?u tiên trong L ra */
                int x = top(&L);
                pop(&L);
                if (mark[x] != 0) // Ðã duy?t r?i, b? qua
                    continue;
                printf("%d\n", x);
                mark[x] = 1; //Ðánh d?u nó dã duy?t
                             /* L?y các d?nh k? c?a nó */
                List list = neighbors(G, x);
                /* Xét các d?nh k? c?a nó */
                for (j = 1; j <= list.size; j++)
                {
                    int y = element_at(&list, j);
                    push(&L, y);
                }
            }
        }
}
