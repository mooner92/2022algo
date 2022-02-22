#include <iostream>
#include <string>
using namespace std;

int main(){
    string ex1;
    getline(cin,ex1);
    sort(ex1.begin(),ex1.end());
    int cnt[26];
    int index,max=0;
    bool overlap = false;

    


    for(int i=0;i<26;i++){
        if(max<cnt[i]){
            max = cnt[i];
            index = i;
            overlap = false;

        }
        else if(max == cnt[i]){
            overlap = true;
        }
    }
    if(overlap){
        cout << "?";

    }
    else{
        cout << char(index);
    }
}