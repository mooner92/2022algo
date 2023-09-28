#include <stdio.h>

int main()
{
    int n, i, j, x = 1, y = 0, num = 1;
    int arr[100][100];

    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        arr[0][i] = arr[n + 1][i] = 1;
        arr[i][0] = arr[i][n + 1] = 1;
    }

    while (num <= n * n)
    {
        while (arr[x][y + 1] == 0)
        {
            y++;
            arr[x][y] = num++;
        }
        while (arr[x + 1][y] == 0)
        {
            x++;
            arr[x][y] = num++;
        }
        while (arr[x][y - 1] == 0)
        {
            y--;
            arr[x][y] = num++;
        }
        while (arr[x - 1][y] == 0)
        {
            x--;
            arr[x][y] = num++;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
////