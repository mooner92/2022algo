#include <stdio.h>
int x;
int ds[11];
void dfs(int n, int k)
{
    if (n == x)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", ds[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = k; i <= 6; i++)
        {

            ds[n] = i;
            dfs(n + 1, k);
        }
    }
}
int main()
{
    scanf("%d", &x);
    dfs(0, 1);
}

//