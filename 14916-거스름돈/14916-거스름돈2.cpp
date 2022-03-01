#include <iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin >> n;
    if(n==3 || n==1){     //1원과 3원만 아니면 전부 변환 가능
        cout <<"-1";
        return 0;
    }
    while(n!=0){          //5원을 계속 빼주면서 sum++을 해줌
        if(n>5){
            n-=5;
            sum++;
        }
        else if(n<=5){     //구현을 어떻게 해야할지 감이 안와서 swich로 무식하게 풀어봄
            switch (n)
            {
            case 5:
                cout <<sum+1;
                n=0;
                break;
            case 4:
                cout <<sum+2;
                n=0;
                break;
            case 3:
                cout <<sum+3;
                n=0;
                break;
            case 2:
                cout <<sum+1;
                n=0;
                break;
            case 1:
                cout <<sum+2;
                n=0;
                break;
            default:
            n=0;           //n값 0으로 초기화는 루프를 멈추기 위함
                break;
            }
        }
    }
}