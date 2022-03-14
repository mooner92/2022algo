#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> k;
    int tc,t;
    cin>>tc>>t;
    for(int i=0;i<tc;i++){
        k.push(i+1);
    }   // 배열 생성해줌
    //vector<int>::iterator iter = k.begin();
    cout<<"<";
    while(!k.empty()){
        for(int i=0;i<t-1;i++){
            k.push(k.front());
            k.pop();
        }
        cout << k.front();
		k.pop();
 
		if (!k.empty()) {
			cout << ", ";
		}
    }
    cout<<">\n";

}