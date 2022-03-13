#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll fib(ll a){  //피보나치 수열의 a번째 항을 리턴
    vector<ll> u;
    u.push_back(1);
    u.push_back(1);
    for(int i=2;i<a;i++){
        ll w = u[i-2]+u[i-1];
        u.push_back(w);
    }
    return u[a-1];
}


int main(){

    vector<ll> e;
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        ll p,q;
        cin>>p>>q;
        ll r = fib(p);
        //cout <<r <<"\n\n\n";
        cout <<"Case #"<< i <<":"<<" "<< r%q<<"\n";
        

    }

}

