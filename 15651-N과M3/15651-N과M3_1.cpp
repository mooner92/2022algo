#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX];
int v[MAX];
void dfs(int k, int l)
{
    if (l == m)
    {
        for (int i = 0; i < l; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = k; i <= n; i++)
    {
        arr[l] = i;
        dfs(k, l + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dfs(1, 0);
}