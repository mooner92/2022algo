#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string x;

    while(1){
        stack<char> t;
        string s;
        getline(cin,s);
        if(s.size()==1 && s[0]=='.'){   //한자리고 .이 들어오면 break;
            break;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')' || s[i]=='[' || s[i]==']'){ //i번째가 괄호라면
                t.push(s[i]);
            }  // 괄호로 이루어진 stack을 작성해줌
        }
        

    }

}