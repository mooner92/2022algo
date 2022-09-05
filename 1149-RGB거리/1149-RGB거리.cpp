#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int rgb[1002][3] = {
        0,
    };
    int n, r, g, b;
    const int p1 = 0, p2 = 1, p3 = 2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> g >> b;
        rgb[i][p1] = min(rgb[i - 1][1], rgb[i - 1][2]) + r;
        rgb[i][p2] = min(rgb[i - 1][0], rgb[i - 1][2]) + g;
        rgb[i][p3] = min(rgb[i - 1][0], rgb[i - 1][1]) + b;
    }
    cout << min(min(rgb[n][0], rgb[n][1]), rgb[n][2]);
}