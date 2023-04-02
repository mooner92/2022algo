#include <iostream>
using namespace std;
int ds[130][130]; // 0~127 idx로 사용  0~63 , 64~127
int siz;
int wcnt = 0, bcnt = 0;
void rec(int x, int y, int n)  //정사각형이니 n만 넘겨주기
{
    int tmp = 0;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (ds[i][j])
            {
                tmp++;
            }
        }
    }
    if (!tmp)
        wcnt++;
    else if (tmp == n * n)
        bcnt++;
    else
    {
        rec(x, y, n / 2);
        rec(x, y + n / 2, n / 2);
        rec(x + n / 2, y, n / 2);
        rec(x + n / 2, y + n / 2, n / 2);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> siz;
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            cin >> ds[i][j];
        }
    }
    rec(0, 0, siz);
    cout << wcnt << "\n"
         << bcnt;
}