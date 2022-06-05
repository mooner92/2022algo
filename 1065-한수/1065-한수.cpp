#include <iostream>
using namespace std;

int searchAns(int h)
{ // h만큼 반복
    int cnt = 0;
    for (int i = 1; i <= h; i++)
    { // 1~h까지 반복
        if (i < 100)
            cnt++;
        else if (i >= 100 && i < 1000)
        {
            int a, b, c;
            int i1 = i;
            c = i1 % 10;
            i1 /= 10;
            b = i1 % 10;
            i1 /= 10;
            a = i1;
            if (a == b && b == c)
                cnt++;
            else if (a + c == b * 2)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int s;
    cin >> s;
    int ans = searchAns(s);
    cout << ans;
}
