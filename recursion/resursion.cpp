#include <iostream>
using namespace std;

void countNum(int num)
{
  if (num == 1)
  {
    cout << "Num : " << num << endl; // 재귀함수는 탈출조건이 있어야함
    return;
  }
  else
  {
    cout << "Num : " << num << endl;
    countNum(num - 1);
  }
}

int main()
{
  countNum(5);
  return 0;
}

////
// 출처: https://see-ro-e.tistory.com/21 [SeeRoE 프로그래밍 기록]