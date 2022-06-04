#include <iostream>
#include <vector>
using namespace std;

int search4x4(vector<string> v1, int i1, int j1)
{
    // width,height
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        // case1 width
        if (v1[i1 + i][j1] == 'E' || v1[i1 + i][j1] == 'I')
        {
            if (v1[i1 + i][j1 + 1] == 'N' || v1[i1 + i][j1 + 1] == 'S')
                if (v1[i1 + i][j1 + 2] == 'T' || v1[i1 + i][j1 + 2] == 'F')
                    if (v1[i1 + i][j1 + 3] == 'P' || v1[i1 + i][j1 + 3] == 'J')
                    {
                        cnt++;
                        // cout << "width1\n";
                    }
        }
        else if (v1[i1 + i][j1] == 'P' || v1[i1 + i][j1] == 'J')
        {
            if (v1[i1 + i][j1 + 1] == 'T' || v1[i1 + i][j1 + 1] == 'F')
                if (v1[i1 + i][j1 + 2] == 'N' || v1[i1 + i][j1 + 2] == 'S')
                    if (v1[i1 + i][j1 + 3] == 'E' || v1[i1 + i][j1 + 3] == 'I')
                    {
                        cnt++;
                        // cout << "width2\n";
                    }
        }

        // case2 height
        if (v1[i1][j1 + i] == 'E' || v1[i1][j1 + i] == 'I')
        {
            if (v1[i1 + 1][j1 + i] == 'N' || v1[i1 + 1][j1 + i] == 'S')
                if (v1[i1 + 2][j1 + i] == 'T' || v1[i1 + 2][j1 + i] == 'F')
                    if (v1[i1 + 3][j1 + i] == 'P' || v1[i1 + 3][j1 + i] == 'J')
                    {
                        cnt++;
                        // cout << "height1\n";
                    }
        }
        else if (v1[i1][j1 + i] == 'P' || v1[i1][j1 + i] == 'J')
        {
            if (v1[i1 + 1][j1 + i] == 'T' || v1[i1 + 1][j1 + i] == 'F')
                if (v1[i1 + 2][j1 + i] == 'N' || v1[i1 + 2][j1 + i] == 'S')
                    if (v1[i1 + 3][j1 + i] == 'E' || v1[i1 + 3][j1 + i] == 'I')
                    {
                        cnt++;
                        // cout << "height2\n";
                    }
        }
    }
    // case 3 diagonal

    // LT->RB && RB->LT
    if (v1[i1][j1] == 'E' || v1[i1][j1] == 'I')
    {
        if (v1[i1 + 1][j1 + 1] == 'N' || v1[i1 + 1][j1 + 1] == 'S')
            if (v1[i1 + 2][j1 + 2] == 'T' || v1[i1 + 2][j1 + 2] == 'F')
                if (v1[i1 + 3][j1 + 3] == 'P' || v1[i1 + 3][j1 + 3] == 'J')
                {
                    cnt++;
                    // cout << "dia1\n";
                }
    }
    else if (v1[i1][j1] == 'P' || v1[i1][j1] == 'J')
    {
        if (v1[i1 + 1][j1 + 1] == 'T' || v1[i1 + 1][j1 + 1] == 'F')
            if (v1[i1 + 2][j1 + 2] == 'N' || v1[i1 + 2][j1 + 2] == 'S')
                if (v1[i1 + 3][j1 + 3] == 'E' || v1[i1 + 3][j1 + 3] == 'I')
                {
                    cnt++;
                    // cout << "dia2\n";
                }
    }

    // LB->RT && RT->LB
    if (v1[i1 + 3][j1] == 'E' || v1[i1 + 3][j1] == 'I')
    {
        if (v1[i1 + 2][j1 + 1] == 'N' || v1[i1 + 2][j1 + 1] == 'S')
            if (v1[i1 + 1][j1 + 2] == 'T' || v1[i1 + 1][j1 + 2] == 'F')
                if (v1[i1][j1 + 3] == 'P' || v1[i1][j1 + 3] == 'J')
                {
                    cnt++;
                    // cout << "dia3\n"; // Bcase 1
                }
    }
    else if (v1[i1 + 3][j1] == 'P' || v1[i1 + 3][j1] == 'J')
    {
        if (v1[i1 + 2][j1 + 1] == 'T' || v1[i1 + 2][j1 + 1] == 'F')
            if (v1[i1 + 1][j1 + 2] == 'N' || v1[i1 + 1][j1 + 2] == 'S')
                if (v1[i1][j1 + 3] == 'E' || v1[i1][j1 + 3] == 'I')
                {
                    cnt++;
                    // cout << "dia4\n";
                }
    }

    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i <= (n - 4); i++) // y축이동
    {
        for (int j = 0; j <= (m - 4); j++) // x축이동
        {                                  //가로세로 :-4까지 비교 == 전체 칸 비교
            ans += search4x4(v, i, j);
        }
    }
    cout << ans;
}
