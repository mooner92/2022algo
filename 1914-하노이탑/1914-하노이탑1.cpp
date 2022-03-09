#include <iostream>
#include <algorithm>
using namespace std;
 
string add(string num1, string num2)  //string으로 문자를 받아서 한자리씩 더함
{
	long long sum = 0;
	string result;
 
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
 
	return result;
}
 
void hanoi(int n, int from, int by, int to)
{
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}
 
int main(int argc, char* argv[])
{
	int n;
	int sub;
	string num;
	string result;
 
	scanf("%d", &n);
 
	if (n == 1) {
		result = '1';
	}
	else {
		num = "2";
		for (int i = 0; i < n - 1; ++i) {
			result = add(num, num);
			num = result;
		}
		sub = result.back() - '0';
		result.pop_back();
		sub -= 1;
		result.push_back(sub + '0');
	}
 
	cout << result << endl;
 
	if (n <= 20) {
		hanoi(n, 1, 2, 3);
	}
 
	return 0;
}