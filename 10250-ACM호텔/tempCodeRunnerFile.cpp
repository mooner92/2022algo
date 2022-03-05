#include <iostream>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++){
        int row,col,g;
        cin >>row>>col>>g;
        cout <<((100*(g%row))+((g/col)+2)) << endl;
    }
}