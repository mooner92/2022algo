#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//int l[4002];
int main(){
    vector<int> v;
    int a,s,d,f;
    int sum=0;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
        //l[a]+=1;  //도수분포표
        sum+=a;
    }
    sort(v.begin(),v.end(),greater<>());
    //sort(q.front(),q.back(),greater<>());  //내림차순으로 도수분포표 정렬

    s = (N/2)+1; //중앙값
    a = floor(sum/N + 0.5);  //반올림한 산술평균
    f = v.front() - v.back(); //범위

    /*if(l[0]==l[1]){
        int tmp=0;
        while (1)
        {
            if(l[tmp]!=l[tmp+1]){
                d = tmp+1;
                break;
            }
        }
    }
    else
        d = l[0];
    */
    cout<<a<<"\n"<<s<<"\n"<<d<<"\n"<<f;



}