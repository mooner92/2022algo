#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    for(int i=0;i<3;i++){
        int f;
        cin>>f;
        a.push_back(f);
    }
    sort(a.begin(),a.end());
    /*for(int i=0;i<3;i++){
        cout << a[i] <<"\n";
    }*/
    
    if((a[0]==a[1] || a[1]==a[2]) || a[0]+a[1]==a[2]){
        cout <<"S";
    }
    else 
        cout << "N";

}