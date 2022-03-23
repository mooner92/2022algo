#include <iostream>
using namespace std;
using  ll=long long;
#define MAX  20000000   //20000000만큼의 메모리를 할당해야하기 때문에 메모리가 터짐

ll q[MAX];
ll p[MAX];
//ll sor[500001];
int main(){   //도수분포표 사용
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll d;
        cin>>d;
        q[d+10000000]++;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        ll d;
        cin>>d;
        cout << q[d+10000000] << " ";
    }

    //p와q에 숫자들 저장해줌

}