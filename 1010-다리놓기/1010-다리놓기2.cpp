#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 1)
        return 1;
    else
        return fibo(n - 1) + n;
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
        cout << fibo(dummy + 1) << "\n";
    }
}