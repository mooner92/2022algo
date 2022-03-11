#include <iostream>
using namespace std;

int main(){
    long long r, c, n, x, y;
    cin>>r>>c>>n;
    if (r%n)
        x = r/n + 1;
    else
        x = r/n;
    if (c%n)
        y = c/n + 1;
    else
        y = c/n;
    cout<<x*y;
    return 0;
}