#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long e[200001] = {0};
bool g[200001] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> ch;
    int n, q, d, s, cmd, sto;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
        e[i] += e[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> d;
            g[d] = 1;
        }
        else
        {
            cin >> s >> d;
            sto = s;
            for (int a = d - 1; a > s; a--)
            {
                if (g[a])
                {
                    sto = a;
                    break;
                }
            }
            cout << e[d] - e[sto] << '\n';
        }
    }
}