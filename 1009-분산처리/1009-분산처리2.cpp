#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int q, w;
        cin >> q >> w;
        q %= 10;
        int ans = 1;
        for (int j = 0; j < w; j++)
        {
            ans = (ans * q) % 10;
        }
        if (ans == 0)
        {
            cout << 10 << "\n";
        }
        else
            cout << ans << "\n";
    }
}