#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a,string b){
    if(a.length()==b.length()){
        return a<b;
    }  //길이가 같으면 사전순으로
    else
        return a.length()<b.length();
        //길이가 다르면 길이순으로
}
string s[20001];
int main(){
    //vector<string> s;
    
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        string g;
        cin>>g;
        //s.push_back(g);
        s[i] = g;
    }
    //s.begin(),s.end(),compare
    sort(s,s+tc,compare);    //문자열벡터를 정렬
    for(int j=0;j<tc;j++){
        if(s[j]==s[j-1])
            continue;
        cout << s[j]<<"\n";
    }

}   //벡터는 런타임에러  문자열배열은 정답이 나옴