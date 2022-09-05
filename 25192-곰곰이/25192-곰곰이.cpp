#include <iostream>
#include <vector>
using namespace std;

bool findI(vector<string> s1, string str)
{ // s에서 dummy1찾기
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == str)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n, "");
    vector<bool> snap(n, false);
    int p = 0; // enter의 경우를 제외한 pivot p를 선언하여 유효인덱스로 사용
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string dummy1;
        cin >> dummy1;
        if (dummy1 == "ENTER")
        { // enter가 입력되면 해시테이블-1로 초기화, 메인테이블은 빈칸으로 초기화
            fill(snap.begin(), snap.end(), false);
            fill(s.begin(), s.end(), "");
            p = 0;
        }
        else
        {
            if (findI(s, dummy1))
                cnt++; // dummy1이 s에 없을 때  cnt++
            s.push_back(dummy1);
            p++;
        }
    }
    cout << cnt;
}

/*
#if
*/