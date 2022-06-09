#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    double x, y, ans = 0;
    cin >> x >> y;
    int c = x / y; //소수점은 버릴거임
    double d = y / x;
    cout << d << "\n";
    cout << 6.0 * d / 106.0 << "\n";
    cout << c;
}