#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, k, q[100001] = {0}, w[100001] = {0}, sum = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &w[i]);
    }
    int point[100001][2] = {
        0,
    };
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    for (int i = 0; i < k; i++)
    {
        int min = 99999999;
        for (int j = 0; j < k; j++)
        {
            if (i != j && (abs(point[i + 1][0] - point[i][0]) + abs(point[i + 1][1] - point[i][1])) < min)
            {
                min = abs(point[i + 1][0] - point[i][0]) + abs(point[i + 1][1] - point[i][1]);
            }
        }
        printf("%d ", min);
        sum += min;
    }
    printf("\n%d", sum);
} /////////