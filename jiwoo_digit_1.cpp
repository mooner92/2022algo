#include <stdio.h>
#include <math.h>
#include <string.h>
char input[100];
int x;
int i = 0;
long long int n;
long long int a;
char ans[100];

void M1()
{
    for (;;)
    {
        if (n == 0)
            break;
        else
        {
            ans[i] = '0' + (n % a);
            i++;
            n /= a;
        }
    }
}
///////////////m2 수정 필요
void M2()
{
    for (;;)
    {
        if (n == 0)
            break;
        else
        {
            if (n % a > 9)
            {
                ans[i] = 'A' + ((n % a) - 10);
            }
            else
            {
                ans[i] = '0' + (n % a);
            }
            i++;
            n /= a;
        }
    }
}

long long honer(int b)
{
    long long sum = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
            sum = sum * x + (input[i] - 'A' + 10);
        else
            sum = sum * x + (input[i] - '0');
    }
    memset(input, '\0', sizeof(input));
    return sum;
}

int main()
{
    for (;;)
    {
        memset(ans, '\0', sizeof(ans));
        scanf("%d", &x);
        if (x == 0)
            break;
        scanf("%s", input);

        scanf("%lld", &a);
        if (input[0] == '0' && strlen(input) == 1)
        {
            printf("0\n");
            continue;
        }
        n = honer(x);
        // printf("\n<-%lld->\n", n);
        if (a <= 10)
            M1();
        else
            M2();
        for (i = strlen(ans) - 1; i >= 0; i--)
        {
            printf("%c", ans[i]);
        }
        i = 0;
        printf("\n");
        // strcpy(ans, "");
    }
    return 0;
}