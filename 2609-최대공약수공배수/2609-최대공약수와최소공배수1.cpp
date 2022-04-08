#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b, int c)
{
    return a * b / c;
}
int main()
{
    int a, b, c, d;
    cin >> a >> b;
    c = gcd(a, b);
    d = lcm(a, b, c);
    cout << c << " " << d;
}