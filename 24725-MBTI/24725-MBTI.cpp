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

void search4x4(vector<string> v1, int i1, int j1, int n1, int m1)
{
    // case1 width
    for (int i = 0; i < n1; i++)
    {
    }
}