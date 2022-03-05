#include <iostream>
#include <string>
using namespace std;
int main(){
    int size,ans=0;
    cin >> size;
    string a,b;    //char배열로 하면 틀렸습니다 가 나옴
    cin >>a >> b;
    for(int i=0;i<size;i++){
        if(a[i]!=b[i]) ans++;
    }
    cout <<ans;

    
}