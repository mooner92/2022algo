#include <iostream>
#include <algorithm>
using namespace std;
int k[11];
int main(){
    for(int i=1;i<=10;i++){
        int m,p;
        cin >> m>>p;
        p-=m;
        k[i] =k[i-1]+p;
    }
    sort(k,k+10);
    cout << k[9];
}