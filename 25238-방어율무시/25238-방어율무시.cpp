#include <iostream>
using namespace std;
int main()
{
    double n, m;
    cin >> n >> m;
    double p = n - (n * m / 100);
    if (p >= 100)
        cout << "0";
    else
        cout << "1";
}