#include <iostream>
using namespace std;
int b[7];
int main(){
    int a[7] = {1,1,2,2,2,8};
    for(int i=0;i<6;i++){
        cin >> b[i];
        a[i]-=b[i];
    }
    for(int j=0;j<6;j++){
        cout << a[j] << " ";
    }


}