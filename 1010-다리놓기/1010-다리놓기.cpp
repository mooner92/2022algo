#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int n, m;
        ll dummy = 0;
        cin >> n >> m;
        if (n == m)
        {
            cout << 1 << "\n";
            continue;
        }
        if (n > (m - n))
        {
            dummy = n;
        }
        else
            dummy = m - n;
        ll ans = 1;
        for (int j = m; j > dummy; j--)
        {
            ans *= j;
        }
        cout << ans << "\n";
    }
}