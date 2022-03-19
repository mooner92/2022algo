#include <iostream>
using namespace std;
int e=0;
int pizza(int n){
    if(n==1){
        return 0;
    }
    int q,w;
    q = n/2;  //n의반값
    w = n-q;  //n-q
    e+=(q*w);
    return pizza(q) + pizza(w);
}

int main(){
    int r=0;
    cin>>r;
    int t = pizza(r);
    cout <<e;
}