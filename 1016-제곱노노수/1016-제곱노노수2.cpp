#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll min,max;
    cin>>min>>max;

    ll ans = max-min+1;
    vector<bool> s(max-min+1,false);
    ll i = 2;

    while((i*i)<=max){
        ll N = min/(i*i);
        if(min % (i*i) != 0){
            N++;
        }
        while(N*(i*i)<=max){
            if(s[N*(i*i)-min]==false){
                s[N*(i*i)-min]=true;
                ans--;
            }
            N++;
        }
        i++;
    }
    cout<<ans;
}
