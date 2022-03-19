#include <iostream>
using namespace std;
using ll = long long;
ll e=0;
ll pizza(int n){
    if(n==1){
        return 0;
    }
    ll q,w;
    q = n/2;  //n의반값
    w = n-q;  //n-q
    e+=(q*w);
    return pizza(q) + pizza(w);
}

int main(){
    ll r=0;
    cin>>r;
    ll t = pizza(r);
    cout <<e;
}