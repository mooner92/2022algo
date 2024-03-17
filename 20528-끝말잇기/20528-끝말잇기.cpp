#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    char c;
    bool check = true;
    cin >> s;
    c = s[0];
    for (int i = 1; i < n; i++)
    {
        cin >> s;
        if (s[0] != c)
            check = 0;
    }
    if (check)
        cout << "1";
    else
        cout << "0";
}
////