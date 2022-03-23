#include <iostream>
#include <queue>
using namespace std;
queue<int> a;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        a.push(i);   //1부터 n까지 큐에 저장
    }
    while(a.size()!=1){  //a.size가 1이면 종료
        a.pop();
        int tmp = a.front();
        a.push(tmp);
        a.pop();
    }
    cout << a.front();

}