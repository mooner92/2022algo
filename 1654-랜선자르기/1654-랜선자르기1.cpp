#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

ll K, N;
vector<ll> vk;

inline bool solution(ll n) {
    ll ret = 0;
    for(int i=0; i<vk.size(); i++) {
        ret += vk[i]/n;
    }
    
    if(ret >= N) return true;
    else return false;
}

// l 은 begin, r 은 end (미포함)
inline ll parametric(ll l, ll r) {
    if(l+1 >= r) return l;
    
    ll mid = (l+r) / 2; // 우편향
    
    if(solution(mid)) return parametric(mid, r);
    else return parametric(l, mid);
}

int main() {
    cin >> K >> N;
    
    ll mx = 0;
    ll temp;
    for(int i=0; i<K; i++) {
        cin >> temp;
        vk.push_back(temp);
        
        mx = (mx < temp) ? temp : mx;
    }
    
    ll ans = 0;
    ans = parametric(1, mx+1);
    cout<<ans<<"\n";
}

/*

이미 있는 랜선 K 개 :
1 <= K <= 10,000

필요한 랜선 N 개 :
1 <= N <= 1,000,000
    
@@@@ 풀이방법 @@@@

parametric search

binary search 해서 나온 값으로
check
- 통과 시 left
- 탈락 시 right

@@@@@@@@@@@@@@@

해 : N 개를 만들 수 있는 랜선의 최대 길이

*/