#include <iostream>
using namespace std;
int k[5];
int main(){
    int a,b,stan=0;
    cin >> a>>b;
    stan = a*b;
    for(int i=0;i<5;i++){
        cin >> k[i];
        k[i] -=stan;
    }
    for(int i=0;i<5;i++){
        cout << k[i] <<" ";
    }

}