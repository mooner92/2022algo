#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int tc;
    int rank=1,ans=1; //5명이 있다면 4번째항까지 비교를 하되 5등까지 있어야함 ans = 등수
    cin>>tc;
    vector<pair<int,int>> k;
    for(int i=0;i<tc;i++){
        int w,h;
        cin>>w>>h; // 무게,키를 차례대로 받아줌
        k.push_back(make_pair(w,h)); // pair에 저장
    }
    //sort(k.begin(),k.end(),greater<>()); //greater임시객체 정렬해주면 안됨
    for(int i=0;i<tc;i++){ //마지막항 까지만 비교해주기 위하여 마지막항 전까지의 루프를 돌려줌
        //cout <<k[i].first <<" "<< k[i].second << "\n";  //내림차순 출력 잘 됨
        int r=1;
        for(int j=0;j<tc;j++){
            if(i!=j){
                if(k[i].first<k[j].first && k[i].second<k[j].second){
                    r++;
                }
            }
        }
        cout <<r << " ";
    }
}