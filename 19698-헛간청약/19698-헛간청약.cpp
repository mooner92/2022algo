#include <iostream>
using namespace std;
int main()
{
    int N, W, H, L;
    cin >> N >> W >> H >> L;
    int q, w;
    q = W / L;
    w = H / L;
    int ans = q * w;
    if (N < ans)
        cout << N;
    else
        cout << ans;
}