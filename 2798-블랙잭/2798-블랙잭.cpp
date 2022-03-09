#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    vector<int> k;
    cin >>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin >>a;
        k.push_back(a);  //벡터로 n칸짜리 배열 생성후 수 입력
    }
    int b = k.size();
    int min=300000;
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            if(i==j){    //같으면 다음루프로
                break;
            }
            for(int h=0;h<b;h++){
                if(j==h || i==h){  //하나라도 같으면 다음루프로
                    break;
                }
                int value=k[i]+k[j]+k[h];
                int r = m-value;
                    if(r>=0){
                    if(r<min){
                    min=r;
                    }
                }
            }
        }
    }
    cout <<m-min;
    
}