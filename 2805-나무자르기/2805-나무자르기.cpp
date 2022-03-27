#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
vector<int> k;
int main(){
    ll n,h;
    cin>>n>>h;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        k.push_back(a);
    }  //vector작성
    sort(k.begin(),k.end());
    while(1){
        int half = k.size()/2;  //바이너리서치의 피봇
        if(k[half]);
    }
    


}