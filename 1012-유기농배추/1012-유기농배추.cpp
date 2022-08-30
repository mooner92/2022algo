#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v1(51, vector<int>(51, 0));
vector<vector<bool>> visited(51, vector<bool>(51, 0));
int w, h;
//상하좌우
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int gx = x + dx[i];
        int gy = y + dy[i];

        if (gx < 0 || gx >= w || gy < 0 || gy >= h)
            continue;
        if (!v1[gx][gy] || visited[gx][gy])
            continue;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, k, x, y;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> w >> h >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            v1[x][y] = 1;
        }
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (v1[j][k] == 1)
                {
                    dfs(j, k);
                }
            }
        }
    }
}