#include <iostream>
using namespace std;

void Hanoi(int n, char from, char via, char to) 
{
	// 재귀함수는 반드시 끝나는 조건이 있어야 한다
	if (n == 1) {
		cout << from << " -> " << to << endl;
	}
	else {
		Hanoi(n - 1, from, to, via);
		cout << from << " -> " << to << endl;
		Hanoi(n - 1, via, from, to);
	}
}

int main()
{
	Hanoi(4, 'A', 'B', 'C');
}