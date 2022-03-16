#include<iostream>
using namespace std;

int N, ans, cnt, temp;

int main()
{
	
	cin >> N;

	ans = 0; // 영화 제목
	cnt = 0; // 현재 몇번쨰 종말의 수인지

	while (cnt != N)  //템프가 0이된 상태로 다시 루프 시작
	{
		ans++;  //전 루프에서 666이었어도 ans는 666 temp =0
		temp = ans;  //0이된 temp에 다시 ans값을 넣어줌

		// 수에 6이 적어도 3개이상 들어가는지 판별
		while (temp != 0) 
		{
			if (temp % 1000 == 666) // 종말의 숫자라면
			{
				cnt++;  
				break;
			}
			else temp /= 10; // 일의 자리수를 삭제하여 0이되면 루프종료
		}
	}
	cout << ans;
}