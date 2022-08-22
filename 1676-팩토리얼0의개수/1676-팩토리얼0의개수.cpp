#include <iostream>
using namespace std;
int p = 1;
int ans = 0;
void factans(long long n)
{
    if (n == 1)
        return;
    p *= n;
    if (p % 10 == 0)
    {
        p /= 10;
        ans++;
    }
    if (p > 10000)
    {
        p %= 10000;
    }
    factans(n - 1);
}
int main()
{
    long long n;
    scanf("%lld", &n);
    if (n == 0)
    {
        cout << "1";
        return 0;
    }
    factans(n);
    printf("%d", ans);
}