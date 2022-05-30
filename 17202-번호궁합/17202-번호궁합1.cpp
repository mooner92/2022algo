#include <cstdio>
int A[18];
int main()
{
    for (int i = 0; i < 16; i += 2)
        A[i] = getchar() - '0';
    getchar();
    for (int i = 1; i < 16; i += 2)
        A[i] = getchar() - '0';
    for (int j = 15; j > 1; j--)
        for (int i = 0; i < j; i++)
            A[i] = (A[i] + A[i + 1]) % 10;
    return !printf("%d%d", A[0], A[1]);
}