#include <iostream>
using namespace std;
#define FastFC cin.tie(NULL),cout.tie(NULL),ios::sync_with_stdio(false)

void print_case(int cnt);
int main() {
	FastFC;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		print_case(i);
	}
	return 0;
}
void print_case(int cnt) {
	long long P, Q; cin >> P >> Q;
	cout << "Case #" << cnt << ": ";
	long long first = 1, second = 1, third = 2;
	if (P == 1){
        if(Q==1){
            cout <<"0";
        }
        else
            cout << first;
    }
	else if (P == 2)cout << second;
	else {
		for (int i = 3; i <= P; i++) {
			third = (second + first) % Q;
			first = second % Q;
			second = third % Q;
		}
		cout << third % Q;
	}
	cout << "\n";
}