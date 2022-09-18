#include <iostream>
#include <string>
#include <stack>
using namespace std;

void check(string s){
    string r =s;
    int tmp=0;
    for(int i=0;i<r.size();i++){
        if(r[i]=='('){
            tmp+=1;
        }
        else if(r[i]==')'){
            tmp-=1;
        }
        if(tmp<0){  //하나라도 닫힘괄호가 먼저나왔을때 바로 브레이크
            cout << "NO\n";
            break;
        }
    }
    if(tmp==0){  //tmp가 음수구간없이 루프문이 종료되고 tmp가 0이면 완벽한 문장임
        cout<<"YES\n";
    }
    else if(tmp>0)
        cout <<"NO\n"; //끝났는데 tmp값이 남아있으면 열림괄호가 더 많은 것이므로 no를 출력 else로하면 안됨


    //cout으로 출력까지 구현할 것
}


int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        string s;
        cin>>s;
        check(s);
    }

}//

