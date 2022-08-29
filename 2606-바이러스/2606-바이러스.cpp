#include <iostream>
#include <vector>
using namespace std;

bool visited[101] = {};
bool ovisited[101] = {};
int cnt = 0;
void dfs(const vector<vector<int>> &v1, int s)
{
    if (visited[s])
        return;
    visited[s] = true;

    for (int v : v1[s])
    {
        if (ovisited[s])
        {
            ovisited[v] = true;
            cnt++;
        }
        dfs(v1, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<vector<int>> v1(101);
    cin >> n >> m;
    int q, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> q >> w;
        v1[q].push_back(w);
    }
    ovisited[1] = true; // idx 1번 컴퓨터는 숙주
    dfs(v1, 1);
    cout << cnt - 1;
}