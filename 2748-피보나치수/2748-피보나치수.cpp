#include <iostream>
using namespace std;
using ll = long long;

ll fibo(int data){
    ll a[91];
    int e;
    a[0] = 1;
    a[1] = 1;
    for(int i=2;i<data;i++){
        a[i] = a[i-1] + a[i-2];
    }
    return a[data-1];
}

int main(){
    int q;
    cin>>q;
    cout << fibo(q);
}