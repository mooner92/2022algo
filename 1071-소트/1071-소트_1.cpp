#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ds[1002] = {
        0,
    };
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        ds[k]++;
    }
    int min = 99999;
    for (int i = 1; i < 1001; i++)
    {
        if (ds[i] != 0)
        {
            if (ds[i + 1] != 0)
            {
                if (i < min)
                {
                    min = i;
                }
                continue;
            }
        }
    }
}