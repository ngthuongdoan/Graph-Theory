#include <stdio.h>

int main(int argc, char const *argv[])
{
    int row, col, i, j, count = 0;
    scanf("%d %d", &row, &col);
    if (row >= 1 && col <= 100)
    {
        int a[row][col];
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] > 0)
                {
                    count++;
                }
            }
        }
        // printf("\n");
        printf("%d", count);
    }
    return 0;
}
