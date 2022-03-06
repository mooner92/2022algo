#include <iostream>
#include <cmath>
using namespace std;
int a[5],T=0;
int main(){
    for(int i=0;i<5;i++){
        cin>>a[i];
        T+=pow(a[i],2);
    }
    cout << T%10;
  
   
}