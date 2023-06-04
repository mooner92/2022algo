#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= 65 && s[j] <= 90)
            {
                cout << char(s[j] + 32);
            }
            else
                cout << s[j];
        }
        cout << '\n';
    }
}