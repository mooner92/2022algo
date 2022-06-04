#include <iostream>
using namespace std;

int searchAns(int h)
{ // h만큼 반복
    int cnt = 0;
    for (int i = 1; i <= h; i++)
    { // 1~h까지 반복
        if (i < 100)
        {
            cnt++;
        }
        else if (i >= 100 && i < 1000)
        {
            int a, b, c;
            c = i % 10;
            i /= 10;
            b = i % 10;
            i /= 10;
            a = i;
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
