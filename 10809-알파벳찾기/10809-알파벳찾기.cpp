#include <iostream>
#include <string>
using namespace std;
int main(){
    int ex1[27] = {0};
    string s;
    getline(cin,s);
    int stan=0;
    for(int i=97;i<123;i++){
        for(int j=0;j<s.size();j++){
            if(s[j] == (char)i){
                ex1[i-97]+=(j+1);
                break;
            }

        }
    }
   for(int k=0;k<26;k++){
       cout << ex1[k] -1<< " ";
   }

}