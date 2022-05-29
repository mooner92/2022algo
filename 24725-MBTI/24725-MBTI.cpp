#include <iostream>
#include <vector>
using namespace std;

int heightP = 0;
int widthP = 0;
int search4x4(vector<string> v1, int i1, int j1, int n1, int m1)
{
    // width,height
    int cnt = 0;
    int hpv = 0;
    int wpv = 0;
    int crowd = 0;
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
                        wpv++;
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
                        wpv++;
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
                        hpv++;
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
                        hpv++;
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

    if (i1 != 0 || j1 != 0)
    {
        if ((widthP - 1) != 0 && (heightP - 1) != 0)
            cnt -= ((wpv - (widthP - 1)) + (hpv - (heightP - 1)));
    }

    widthP = 0;
    heightP = 0;
    widthP += hpv;
    heightP += wpv;

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
    for (int i = 0; i <= (n - 4); i++)
    {
        for (int j = 0; j <= (m - 4); j++)
        { //가로세로 :-4까지 비교 == 전체 칸 비교
            ans += search4x4(v, i, j, n, m);
        }
    }
    cout << ans;
}
