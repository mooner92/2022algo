#include <iostream>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++){
        int row,col,g,lay,add;
        cin >>row>>col>>g;
        if(g%row==0){
            lay = 100*g;
        }
        else if(g%row!=0){
            lay = 100*(g%row);
        }
        
    }
}