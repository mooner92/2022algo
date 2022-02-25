#include <iostream>
using namespace std;

int main(){
    int k,n,m,exc;
    cin >> k>>n>>m;
    exc=k*n-m;
    if(exc>0){cout << exc;}
    else if(exc<=0){cout << "0";}
}