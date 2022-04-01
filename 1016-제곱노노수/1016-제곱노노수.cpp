#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll=long long;
vector<ll> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=1000000;i++){
        v.push_back(pow(i,2));
    }//제곱수 전부 저장
    int min,max;
    cin>>min>>max;
    int pivot=0;
    ll anscon=0;
    while(1){
        if(v[pivot]>=min && v[pivot]<=max){
            anscon++;
        }
        else if(v[pivot]>max){
            break;
        }
        pivot++;
    }
    ll ans = max-min-anscon;
    if(min==max){
        cout<<ans+1<<"\n";
    }
    else
        cout<<ans<<"\n";

}