#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n,m;
        cin>>n>>m;
        queue<int> q;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            q.push(a);
        } //queue작성
        sort(q.front(),q.back());
        int tmp=1;
        int o = 0; //순서
        while(tmp!=m){
            o++;
            int w = q.front();
            q.pop();
            if(q.front()==w){ //q의 첫 원소와 q의 두번째 원소가 같으면 
                continue;
            }
            else { //다르면
            tmp++;
            }
        }
        cout <<o<<"\n";
    }
}