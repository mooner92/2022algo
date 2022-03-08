#include <iostream>
using namespace std;


int ans(int a,int b){
  if(b ==1)
    return 1;
  if(a ==0)
    return b;
  return (ans(a-1,b) + ans(a,b-1)); //재귀로 합을 계속 늘려줌 처음엔 2항끼리 더해줌 두번째는 4항 세번째는 8항 - - -2^n항을 전부 더해줌 0이나 1이 될 때 까지
}

int main() {
  int T,k,n;
  cin>>T;
  for(int i=0;i<T;i++){
    cin>>k>>n;
    cout<<ans(k,n)<<'\n';
  }
}