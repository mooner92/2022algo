#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
//ll a[250001];
int main(){
    ll N,M,B;
    ll dig_T=0,stack_T=0;
    vector<ll> v;
    cin>>N>>M>>B;
    for(int i=0;i<N*M;i++){
        ll temp;
        cin>> temp;
        v.push_back(temp);
    }//배열에 전부 담음 || v에 전부 담음
    sort(v.begin(),v.end());  //sort 오름차순
    



}