#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;        //문제에는 없지만 string으로 문자까지 처리 가능하게 코딩
    while(true){
        getline(cin,s);
        if(s[0]=='0') break;  //0이면 종료
        int g=s.size();       
        for(int i=0;i<g-1;i++){
            int stan = g-1-i; 
            if(s[i]!=s[stan]){
                cout << "no"<<endl;
                break;
            }
            if(i>=stan){             //첫값과 끝값부터 중앙으로 비교하면서 좁혀오다가 중점을 지날 때까지 no가 출력이 안되면 yes로 처리
                cout <<"yes"<<endl;
                break;
            }
        }
        
        
    }
}