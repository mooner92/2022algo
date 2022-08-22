#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans;
    ans = n / 5;
    ans += n / 25;
    ans += n / 125;
    cout << ans;
}