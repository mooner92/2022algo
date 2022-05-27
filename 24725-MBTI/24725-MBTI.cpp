#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < (n - 4); i++)
    {
        for (int j = 0; i < (m - 4); i++)
        { //가로세로 :-4까지 비교 == 전체 칸 비교
        }
    }
    cout << v[0][0];
}

int search4x4(vector<string> v1, int i1, int j1, int n1, int m1)
{
    // width,height
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        // case1 width
        if (v1[i1 + i][j1] == 'E' || v1[i1 + i][j1] == 'I')
            if (v1[i1 + i][j1 + 1] == 'N' || v1[i1 + i][j1 + 1] == 'S')
                if (v1[i1 + i][j1 + 2] == 'T' || v1[i1 + i][j1 + 2] == 'F')
                    if (v1[i1 + i][j1 + 3] == 'P' || v1[i1 + i][j1 + 3] == 'J')
                        cnt++;
                    else if (v1[i1 + i][j1] == 'P' || v1[i1 + i][j1] == 'J')
                        if (v1[i1 + i][j1 + 1] == 'T' || v1[i1 + i][j1 + 1] == 'F')
                            if (v1[i1 + i][j1 + 2] == 'N' || v1[i1 + i][j1 + 2] == 'S')
                                if (v1[i1 + i][j1 + 3] == 'E' || v1[i1 + i][j1 + 3] == 'I')
                                    cnt++;
        // case2 height
        if (v1[i1][j1 + i] == 'E' || v1[i1][j1] == 'I')
            if (v1[i1 + 1][j1 + i] == 'N' || v1[i1 + 1][j1 + i] == 'S')
                if (v1[i1 + 2][j1 + i] == 'T' || v1[i1 + 2][j1 + i] == 'F')
                    if (v1[i1 + 3][j1 + i] == 'P' || v1[i1 + 3][j1 + i] == 'J')
                        cnt++;
                    else if (v1[i1][j1 + i] == 'P' || v1[i1][j1 + i] == 'J')
                        if (v1[i1 + 1][j1 + i] == 'T' || v1[i1 + 1][j1 + i] == 'F')
                            if (v1[i1 + 2][j1 + i] == 'N' || v1[i1 + 2][j1 + i] == 'S')
                                if (v1[i1 + 3][j1 + i] == 'E' || v1[i1 + 3][j1 + i] == 'I')
                                    cnt++;
    }
    // case 3 diagonal
    for (int i = 0; i < 2; i++)
    {
    }
}