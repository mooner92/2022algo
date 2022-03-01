#include <iostream>
using namespace std;

int main(){
    int exc,fhun=0,thun=0;
    cin>>exc;
    while(exc!=0){
        if(exc>=5){
            if(exc%2==1){
                exc-=5;
                fhun++;
            }
            else if(exc%2==0){
                thun+=(exc/2);

            }
        }

    }
}