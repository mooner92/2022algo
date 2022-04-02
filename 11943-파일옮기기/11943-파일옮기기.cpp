#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int q,w,e,r;
    cin>>q>>w>>e>>r;
    cout<<min((q+r),(w+e));
}