#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v1(101);
bool visited[101] = {};
int cnt = 0;

void dfs(int s)
{
    visited[s] = true;
    for (int i = 0; i < v1[s].size(); i++)
    {
        int y = v1[s][i];
        if (!visited[y])
        {
            dfs(y);
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> q >> w;
        v1[q].push_back(w);
        v1[w].push_back(q);
    }
    dfs(1);
    cout << cnt;
}