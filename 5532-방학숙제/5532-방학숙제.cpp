#include <iostream>
using namespace std;
int main(){
    int l,a,b,c,d;
    cin>>l>>a>>b>>c>>d;
    a = (a%c==0) ? (a/c) : (a/c)+1;
    b = (b%d==0) ? (b/d) : (b/d)+1;
    cout << l - max(a,b);
}