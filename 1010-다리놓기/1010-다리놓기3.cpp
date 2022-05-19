#include <iostream>
using namespace std;
using ll = long long;

ll fact(ll n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        ll n, m;
        cin >> n >> m;
        ll dummy;
        if (n < (m - n))
        {
            dummy = n;
        }
        else
            dummy = (m - n);
        ll g = fact(m) / fact(dummy) * fact(m - dummy);
        cout << g << "\n";
    }
    /**/
}