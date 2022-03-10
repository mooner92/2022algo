#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a;
    for(int i=0;i<5;i++){
        int l;
        cin >> l;
        a.push_back(l);
    }
    int x,y;
    x = a[0]*a[4];
    if(a[2]>=a[4]){
        y = a[1];
    }
    else if(a[2]<a[4]){
        y = a[1] + ((a[4] - a[2])*a[3]);
    }
    cout << min(x,y);
}