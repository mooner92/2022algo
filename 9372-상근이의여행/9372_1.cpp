#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int a,b,c,d;
        cin>>a>>b;
        for(int j=0;j<b;j++){
            cin>>c>>d;
        }
        cout<<a-1<<"\n";
    }
}