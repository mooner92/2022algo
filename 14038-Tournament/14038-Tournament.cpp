#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<char> s;
int main(){
    for(int i=0;i<6;i++){
        char a;
        cin>>a;
        if(a=='W'){
            s.push_back(a);
        }
    }
    if(s.size()==5 || s.size()==6){
        cout << "1";
    }
    else if(s.size()==3 || s.size()==4){
        cout << "2";
    }
    else if(s.size()==1 || s.size()==2){
        cout <<"3";
    }
    else 
        cout <<"-1";
}