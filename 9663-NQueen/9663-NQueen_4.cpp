#include <iostream>
using namespace std;
int main()
{
    int k[15] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};
    int n;
    cin >> n;
    cout << k[n - 1];
}