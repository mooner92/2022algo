#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int tc,t;
    cin>>tc;
    vector<int> k;
    vector<pair<int,int>> g;
    for(int i=0;i<tc;i++){
        int q,w;
        cin>>q>>w;
        g.push_back(make_pair(w,q));  //[q,w]로 이루어진 페어벡터를 생성
    }
    sort(g.begin(),g.end());
    for(int i=0;i<tc;i++){
        cout << g[i].second <<" "<<g[i].first<<"\n";
    }
}