#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> s;
    vector<bool> snap(n, -1);
    for (int i = 0; i < n; i++)
    {
        string dummy1;
        cin >> dummy1;
        if (dummy1 == "ENTER")
        { // enter가 입력되면 해시테이블 -1로 초기화
            fill(snap.begin(), snap.end(), -1);
        }
    }
}