#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int happy=0,sad=0;
    //cout <<s.length()<<"\n";
    for(int i=0;i<s.length()-2;i++){
        if(s[i]==':' && s[i+1]=='-'){
            if(s[i+2]=='('){
                //cout<<"sad"; return 0;
                sad++;
                }
            else if(s[i+2]==')'){
                //cout <<"happy"; return 0;
                happy++;
                }
        }
    }
    if(happy==sad && happy!=0){
        cout <<"unsure";
    }
    else if(happy>sad){
        cout <<"happy";
    }
    else if(happy<sad){
        cout <<"sad";
    }
    else if(happy==0&&sad==0){
        cout <<"none";
    }
}