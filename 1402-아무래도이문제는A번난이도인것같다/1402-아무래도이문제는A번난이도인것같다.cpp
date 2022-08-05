#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a, b;
    int apvt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        while (a != 1)
        {
            for (int j = 2; j <= 9; j++)
            {
                if (a % j == 0)
                {
                    a /= j;
                    apvt += j;
                }
            }
        }
        if (b == apvt)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}