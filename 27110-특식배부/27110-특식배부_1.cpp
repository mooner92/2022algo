#include <iostream>
using namespace std;
int main()
{
    int n;
    int a, sum = 0;
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        sum += (a <= n) ? a : n;
    }
    cout << sum;
}