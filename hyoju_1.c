#include <stdio.h>

int n, m;
int ds[100] = {0};
void kkkk(int level, int sum)
{
    if (sum == m && level == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", ds[i]);
        }
        printf("\n");
    }
    else if (level < n)
    {
        for (int i = 1; i <= 6; i++)
        {
            ds[level] = i;
            kkkk(level + 1, sum + i);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    kkkk(0, 0);
}