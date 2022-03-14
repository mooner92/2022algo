#include <iostream>
#include <string>
using namespace std;

struct stack
{
    int arr[10000];
    int l;

    void init(){
        l = -1;  //l을 -1로 지정
    }
    void push(int d) {
		arr[++l] = d;
	}
	bool empty() {
		return (l < 0);   //init을 해 주는 이유 bool값을 음수와 양수로 나눠서 계산해주기 위함
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		return arr[l--];
	}
	int size() {
		return l + 1;
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return arr[l];
	}

};

int main(){
    int tc;
    cin>>tc;
    ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    stack k;
    k.init();
    for(;tc--;){
        string s;
		int n;
        cin>>s>>n;
        if (s == "push") {
			k.push(n);
		}
		if (s == "pop") {
			cout << k.pop() << "\n";
		}
		if (s == "size") {
			cout << k.size() << "\n";
		}
		if (s == "empty") {
			cout << k.empty() << "\n";
		}
		if (s == "top") {
			cout << k.top() << "\n";
		}


    }
}
