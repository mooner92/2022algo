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
    int b = k.capacity();
    
    int h[b][b][b];
}