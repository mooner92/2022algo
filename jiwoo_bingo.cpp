#include <stdio.h>
int ab[5][5];
int p[25];
int fb[5][5] = {0};
int ans = 0, m, n = 0, tmp = 0;
int k = 0;
int rb(int i, int j);
int cb(int i, int j);
int db(int i, int j);
int main()
{
    int a, b;
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &a);
            ab[i][j] = a;
        }
    }
    for (b = 0; b < 25; b++)
    {
        scanf("%d", &p[b]);
        ++k;
        for (i = 0; i < 5; i++)
        {
            if (n == 1)
                break;
            for (j = 0; j < 5; j++)
            {
                if (n == 1)
                    break;
                if (i * 5 + j + 1 == p[b])
                {
                    fb[i][j] = 1;
                    if (i + j == 4 || i == j)
                        ans += db(i, j);
                    ans += rb(i, j);
                    ans += cb(i, j);
                    if (ans >= 3)
                        n = 1;
                }
            }
        }
    }
    printf("%d", k);
    return 0;
}
int rb(int i, int j)
{
    tmp = 0;
    for (m = 0; m < 5; m++)
    {
        if (fb[i][m] != 1)
        {
            ++tmp;
            break;
        }
    }
    return 1 - tmp;
}
int cb(int i, int j)
{
    tmp = 0;
    for (m = 0; m < 5; m++)
    {
        if (fb[m][j] != 1)
        {
            ++tmp;
            break;
        }
    }
    return 1 - tmp;
}
int db(int i, int j)
{
    tmp = 0;
    if (i + j == 4)
    {
        for (m = 0; m < 5; m++)
        {
            if (fb[m][4 - m] != 1)
            {
                ++tmp;
                break;
            }
        }
    }
    if (i == j)
    {
        for (m = 0; m < 5; m++)
        {
            if (fb[m][m] != 1)
            {
                ++tmp;
                break;
            }
        }
    }
    return 2 - tmp;
}