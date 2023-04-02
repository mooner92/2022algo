#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
    int ds[101][101];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, w, e;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fill(ds[i], ds[i] + n + 1, INF / 2);
        ds[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> q >> w >> e;
        if (ds[q][w] > e)
            ds[q][w] = e;
        // ds[w][q] = e;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ds[i][j] == INF / 2)
                cout << 0 << " ";
            else
                cout << ds[i][j] << " ";
        }
        cout << "\n";
    }
}