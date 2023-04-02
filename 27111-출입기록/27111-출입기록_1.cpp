#include <iostream>
using namespace std;
bool check[200002] = {0};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, w, cnt = 0, max = -9999999;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q >> w;
        if (max <= q)
            max = q;
        if (check[q] == w)
            cnt++;
        else
            check[q] = w;
    }
    for (int i = 1; i <= max; i++)
    {
        if (check[i])
            cnt++;
    }
    cout << cnt;
}