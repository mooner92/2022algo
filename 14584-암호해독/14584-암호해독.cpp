#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n;
    string word[21];
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
    }
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s.find(word[j]) != string::npos)
            {
                cout << s << endl;
                return 0;
            }
        }
        for (int j = 0; j < s.length(); j++)
        {
            s[j] = (s.at(j) - 'a' + 1) % 26 + 'a';
        }
    } /**/
}