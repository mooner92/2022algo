#include <iostream>
using namespace std;

int main(){
    int exc,fhun=0,thun=0,stan=0;
    cin>>exc;
    while(exc!=0){
        if(exc>=5){
            if(exc%2==1){            //5보다 큰 홀수일경우
                exc-=5;              //5보다 크면 계속 빼서 2의배수나 5보다 작게 만들어줌
                fhun++;              //5만큼 뺄 때마다 fhun++
            }
            else if(exc%2==0){       //5보다 큰 짝수일경우
                thun+=(exc/2);       //2로나눈 몫을 thun에 더해줌
                exc%=2;              //0을 남겨서 루프를 끝냄

            }
        }
        else if(exc<5){              //exc가 5보다 작은 경우
            if(exc%2==0){
                thun+=(exc/2);       //2로나눈 몫을 thun에 더해줌
                exc%=2; 
            }
            else if(exc%2==1){
                cout << "-1";
                stan++;
                break;
            }
        }

    }
    if(stan!=1){
        cout << fhun+thun;

    }
}