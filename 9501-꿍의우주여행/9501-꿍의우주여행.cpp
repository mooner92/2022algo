#include <iostream>
using namespace std;

int main(){
    int repeat;
    cin >> repeat;
    for(int i=0;i<repeat;i++){
        int ship,dis,ans=0;
        cin >> ship >> dis;
        for(int j=0;j<ship;j++){
            double v,f,c;
            cin>>v>>f>>c;
            if(((v*f)/c)>=dis){ans++;}
        }
        cout <<ans<<endl;
    }
}