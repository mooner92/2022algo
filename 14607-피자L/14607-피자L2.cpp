#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ll q;
    cin>>q;
    if(q==1)
        cout<<"0";
    else if(q==2){
        cout <<"1";
    }
    else 
        cout<<(q*(q-1))/2;
}