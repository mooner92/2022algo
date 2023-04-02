#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double b, c, a1, a2, k;
    cin >> b >> c >> a1 >> a2;
    k = (((b + sqrt(b * b + (4 * c))) / 2.0));
    cout.precision(10);
    cout << k;
}