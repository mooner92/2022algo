#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        char c[101][101]{""};
        cin >> s;
        int pvt = 0;
        int p = sqrt(s.size());
        for (int j = 0; j < p; j++)
        {
            for (int k = p - 1; k >= 0; k--)
            {
                // cout << s[pvt] << "\n";
                c[k][j] = s[pvt];
                pvt++;
            }
        }
        string ans = "";
        for (int l = 0; l < p; l++)
        {
            for (int g = 0; g < p; g++)
            {
                ans.push_back(c[l][g]);
                // cout << c[l][j];
            }
        }
        cout << ans << "\n";
        // cout << ans << "\n";
    }
}