#include <iostream>
using namespace std;

int main(){
    int r;
    int a[3] = {1,0,0};
    cin >> r;
    for(int i=0;i<r;i++){
        int b,c,tmp=0;
        cin>>b>>c;
        tmp = a[b-1];
        a[b-1] = a[c-1];
        a[c-1] = tmp;

    }
    for(int j=0;j<3;j++){
        if(a[j]==1)
        cout << j+1;
    }
}