#include <iostream>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    int k[testcase];
    for(int i=0;i<testcase;i++){
        int car,sum=0,repeat;
        cin >> car;
        sum+=car;
        cin >> repeat;
        for(int j=0;j<repeat;j++){
            int count,price;
            cin >>count  >>price;
            sum+=(count*price);
        }
        k[i] = sum;
    }
    for(int i=0;i<testcase;i++){   //k배열을 만들어 한번에 출력해줬더니 정답이 나옴
        cout << k[i]  << endl;
    }
}