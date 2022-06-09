#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> s;
    vector<bool> snap(n, false);
    int p = 0; // enter의 경우를 제외한 pivot p를 선언하여 유효인덱스로 사용
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string dummy1;
        cin >> dummy1;
        if (dummy1 == "ENTER")
        { // enter가 입력되면 해시테이블 -1로 초기화
            fill(snap.begin(), snap.end(), false);
        }
        else
        {
            s.push_back(dummy1);
            if (snap[p] == false)
            {
                cnt++;
                snap[p] = true;
            }
            p++;
        }
    }
    cout << cnt;
}