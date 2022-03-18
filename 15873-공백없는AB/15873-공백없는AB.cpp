#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '1')
        {
            if (i + 1 < n.size())//현재 i가 끝이 아닐 경우
            {
                if (n[i + 1] == '0')//뒤에가 10이라면
                {
                    ans += 10;
                    i++;
                }
                else
                    ans += n[i] - '0';
            }
            else//현재 i가 끝이라면
                ans += n[i] - '0';
        }
        else//현재 i가 1이아니라면
            ans += n[i] - '0';
    }
    cout << ans << '\n';
}
