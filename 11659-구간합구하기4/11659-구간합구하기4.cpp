#include <iostream>
using namespace std;
int main()
{
    long long v1[100001] = {
        0,
    };
    long long sum[100001] = {
        0,
    };
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &v1[i]);
        sum[i] = sum[i - 1] + v1[i]; // 부분합 벡터 p_b
    }
    int start, end;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &start, &end);
        printf("%lld\n", sum[end] - sum[start - 1]);
        // 1 3 ---> idx 0 2
    }
}