#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int q,w,e;
    cin>>q>>w>>e;
    if(q+w+e>=100){
        cout << "OK";
    }
    else{
        if(min({q,w,e})==q){
            cout<<"Soongsil";
        }
        else if(min({q,w,e})==w){
            cout<<"Korea";
        }
        else
            cout<<"Hanyang";
    }
}