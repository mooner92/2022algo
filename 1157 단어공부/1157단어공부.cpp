#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int maxcount = 1;
    string identint;
    string identchar;
    string ex1;
    int max=1;
    int g;
    getline(cin,ex1);
    
    for(int i=0;i<ex1.length();i++){
        ex1[i] = tolower(ex1[i]); //소문자로 정렬해서 아스키값 동일하게 맞춰줌 그냥 n~n+32  해도 상관x
    }

    sort(ex1.begin(),ex1.end()); //받은 문자열을 알파벳 서순으로 정리함
    
    for(int j=0;j<ex1.length();j++){
        if(ex1[j]==ex1[j+1]){
            maxcount++;
            identint[j]=maxcount;
            identchar[j]=ex1[j];
        }
        else if(ex1[j]!=ex1[j+1]){
            maxcount = 1;
            identint[j]=maxcount;
            identchar[j]=ex1[j];
        }
    }
    for(int k=0;k<identint.length();k++){
        if(max<identint[k]){
            max=identint[k];
            g=k;
        }
        else if(max==identint[k]){
            cout << "?";
        }
    }
    cout << identchar[g];
}

/*
int value = 0;
    int maxcount = 1;

    if (ex1[j]==ex1[j+1])
        {
            maxcount++;
        }
        else if (ex1[j] != ex1[j+1])
        {
            if(value < maxcount){
                value = maxcount;
                key = ex1[j];
                cout << key << endl;
            }
            else if (value == maxcount){
                cout << "?" << endl;
                exit(0);
            }
            else if (value > maxcount){
                maxcount = 1;
            }
        
        }*/