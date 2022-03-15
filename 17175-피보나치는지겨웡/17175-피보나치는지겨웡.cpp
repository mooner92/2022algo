#include <iostream>
using namespace std;
int re=0;
int fibonacci(int n) { // 호출
    re++;
  if (n < 2) {
    return re;
  }  
  return fibonacci(n-2) + fibonacci(n-1);
}
int main(){
    int a,k;
    cin>>a;
    k = fibonacci(a);
    cout <<k;
}