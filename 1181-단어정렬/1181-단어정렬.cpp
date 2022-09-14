#include <iostream>
#include <string>
#include <vector>
using namespace std;
//두 문자열이 같은경우를 생각하자
int main(){
    int a;
    cin>>a;
    char k[50];     //입력받아 문자열로 복사해준 문자열 s와 비교해줄 dummy배열 생성;
    for(int i=0;i<a;i++){
        string s;
        getline(cin,s);
        char c[50];
        for(int j=0;j<s.size();j++){
            c[j] = s[j];  //c에 s값을 넣어줌 문자열>>문자배열로 인덱스접근이 용이하게 해줌
        }      //strcpy사용을 위해 문자배열에 넣어주는 것
        strcpy(k,c);   //처음에 k값에 넣어줌 >>여기부터 이어서



    }//
}