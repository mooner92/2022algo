#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v1[51][51] = {0};
bool visited[51][51] = {false};

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
        dfs(gx, gy);
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
        int cnt = 0;
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (v1[j][k] == 1 && !visited[j][k])
                {
                    cnt++;
                    dfs(j, k);
                }
            }
        }
        cout << cnt << "\n";
        memset(v1, 0, sizeof(v1));
        memset(visited, 0, sizeof(visited));
    }
} /**/