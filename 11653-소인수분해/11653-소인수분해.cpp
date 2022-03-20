#include <iostream>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  int div=2;  // 인수
  if(n!=1)
  {
    while(n>1)
    {
      if(n%div==0)  // 나눠지면 인수 출력
      {
        printf("%d\n",div);
        n/=div;
      }
      else  // 안나눠지면 인수 증가
      {
        div++;
      }
    }
  }
}