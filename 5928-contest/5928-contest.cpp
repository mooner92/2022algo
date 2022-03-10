#include <iostream>
using namespace std;
int d,h,m;
int main(){
    cin >> d >> h >> m;
    int p = 11 + 11 * 60 + 11 * 60 * 24;
    int ans = m + h * 60 + d * 60 * 24 - p;
    if(ans < 0 ) cout << -1 <<endl;
    else cout << ans <<endl;
}