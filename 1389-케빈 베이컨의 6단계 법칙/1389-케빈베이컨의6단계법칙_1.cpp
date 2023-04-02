#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ds[101][101];

    int n, m, q, w, l = INT16_MAX;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fill(ds[i], ds[i] + n + 1, INT16_MAX);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> q >> w;
        ds[q][w] = 1;
        ds[w][q] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int g = 0;
            for (int j = 1; j <= n; j++)
            {
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
                if (k == n && ds[i][j] != INT16_MAX)
                {
                    g += ds[i][j];
                    p[i] += ds[i][j];
                }
            }
            if (g != 0 && g < l)
                l = g;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == l)
        {
            cout << i;
            return 0;
        }
    }

    /*
for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ds[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "l = " << l;
    */
}