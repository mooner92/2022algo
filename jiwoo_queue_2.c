#include <stdio.h>

int main()
{
    int n, m, cnt = 0, cnt2 = 0;
    char a;
    int st[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &a);
        if (a == 'i')
        {
            scanf("%d", &m);
            st[cnt] = m;
            cnt++;
        }
        else if (a == 'o')
        {
            if (cnt == 0)
            {
                printf("empty\n");
            }
            else
            {
                printf("%d\n", st[cnt2]);
                st[cnt2] = 0;
                ++cnt2;
                --cnt;
            }
        }
        else if (a == 'c')
        {
            printf("%d\n", cnt);
        }
    }
    return 0;
}
