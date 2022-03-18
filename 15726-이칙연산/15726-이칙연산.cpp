#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int q,w,e,r1,r2;
    cin>>q>>w>>e;
    r1 = q*w/e;
    r2 = q/w*e;
    cout << (long long)max(r1,r2);
    
}