#include <iostream>
#include <string>
using namespace std;

void print0(int r){
    for(int i=0;i<r;i++){
        cout << "0";
    }
}

int main(){
    string s1,s2;
    char op;
    cin >>s1>>op>>s2;
    int s1s = s1.size() - 1; 
    int s2s = s2.size() - 1; 

    if(op=='+'){
        if(s1==s2){
            cout << "2";
            print0(s1s);
        }
        else{
            cout << "1"; 
            int maxi = max(s1s, s2s); 
            int mini = min(s1s, s2s); 
            print0(maxi - mini - 1); 
            cout << "1"; print0(mini);

        }

    }
    if(op=='*'){
        cout << "1";
        print0(s1s+s2s);
    }



}
