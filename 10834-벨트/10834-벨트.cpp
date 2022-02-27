#include <iostream>
using namespace std;
int main(){
    int repeat;
    cin >> repeat;
    int pg=0; //시계,반시계 구분
    int ratio=1;
    for(int i=0;i<repeat;i++){
        double a,b;
        int c;
        cin >>a>>b>>c;
        ratio = (ratio / a)*b;   //비율을 설정 후 곱해줌    ratio *=(b/a);는 오류남
        if(c==1) ratio *= (-1);  //반시계 계산
        
    }
    if(ratio<0){ 
        pg=1;
        ratio *=(-1);
    }
    cout << pg <<" "<< ratio;
}//cout << a*b <<endl;