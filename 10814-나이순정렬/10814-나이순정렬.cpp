#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp (pair<int, string> u, pair<int, string> v)
{
    return u.first < v.first;    //u<v일 때 1반환 
}

int main(){
    int tc;
    cin>>tc;
    vector<pair<int,string>> v;
    for(int i=0;i<tc;i++){
        int q;
        string s;
        cin>>q>>s;
        v.push_back(make_pair(q,s));
    }
    stable_sort(v.begin(),v.end(),cmp);    //sort 사용시 문자까지 정렬됨   cmp를 따로 만들어 줌으로써 first항으로만 정렬하게끔 함 
    //sort로 하면 오류남 stable_sort 사용시 잘 됨
    for(int i=0;i<v.size();i++){
        cout <<v[i].first<<" "<<v[i].second<<"\n";
    }
}