#include <iostream>
using namespace std;

long long fibo(int n)
{
    long long j = 0;
    for (int i = 1; i <= n; i++)
    {
        j += i;
    }
    return j;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int n, m;
        cin >> n >> m;
        if (n == m)
        {
            cout << 1 << "\n";
            continue;
        }
        else if (n == 1 || n == (m - 1))
        {
            cout << m << "\n";
            continue;
        }
        int dummy;
        if (n > (m - n))
        {
            dummy = n;
        }
        else
            dummy = (m - n);
        long long k = 0;
        for (int i = dummy; i <= m; i++)
        {
            k += fibo(i);
        }
        cout << k << "\n";
    }
}