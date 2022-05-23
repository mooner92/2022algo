#include <iostream>
using namespace std;
int main()
{
    string s = "";
    cin >> s;
    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'c')
        {
            if (s[i + 1] == '=' || s[i + 1] == '-')
            {
                i += 1;
                ans += 1;
            }
            else
                ans += 1;
        }
        else if (s[i] == 'd')
        {
            if (s[i + 1] == 'z')
            {
                if (s[i + 2] == '=')
                {
                    ans += 1;
                    i += 2;
                } /**/
                else
                {
                    ans += 2;
                    i++;
                }
            }
            else if (s[i + 1] == '-')
            {
                ans += 1;
                i++;
            }
            else
            {
                ans += 1;
            }
        }
        else if (s[i] == 'l')
        {
            if (s[i + 1] == 'j')
            {
                ans += 1;
                i++;
            }
            else
            {
                ans += 1;
            }
        }
        else if (s[i] == 'n')
        {
            if (s[i + 1] == 'j')
            {
                ans += 1;
                i++;
            }
            else
            {
                ans += 1;
            }
        }
        else if (s[i] == 's')
        {
            if (s[i + 1] == '=')
            {
                ans += 1;
                i++;
            }
            else
                ans += 1;
        }
        else if (s[i] == 'z')
        {
            if (s[i + 1] == '=')
            {
                ans += 1;
                i++;
            }
            else
                ans += 1;
        }
        else
        {
            ans += 1;
        }
    }
    cout << ans;
}