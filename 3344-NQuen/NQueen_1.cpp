#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string result;
    if (n % 6 != 2 && n % 6 != 3)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            result += to_string(2 * i - 1) + "\n";
        }
        if (n % 2 == 1)
        {
            result += to_string(n) + "\n";
        }
        for (int i = 1; i <= n / 2; i++)
        {
            result += to_string(2 * i) + "\n";
        }
    }
    else if (n % 6 == 2)
    {

        for (int i = 1; i <= n / 2; i++)
        {
            result += to_string(2 * i) + "\n";
        }
        result += "3\n";
        result += "1\n";
        for (int i = n / 2 + 2; i < n - 1; i++)
        {
            result += to_string(2 * (i - n / 2 + 1) + 1) + "\n";
        }
        result += "5\n";
    }
    else if (n % 6 == 3)
    {
        for (int i = 2; i <= n / 2; i++)
        {
            result += to_string(2 * i) + "\n";
        }
        result += "2\n";

        for (int i = n / 2; i < n - 2; i++)
        {
            result += to_string((i - n / 2 + 2) * 2 + 1) + "\n";
        }
        result += "1\n";
        result += "3\n";
    }

    cout << result;
    return 0;
}
