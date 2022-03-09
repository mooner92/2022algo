#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int n, int from, int via, int to) 
{
	// 재귀함수는 반드시 끝나는 조건이 있어야 한다
     
     if(n<=20){
	    if (n == 1) {
	    	cout << from << " " << to << endl;
	    }
	    else {
		    Hanoi(n - 1, from, to, via);
		    cout << from << " " << to << endl;
	    	Hanoi(n - 1, via, from, to);
	    }
    }
}

int main()
{
    double a;
    cin>>a;
    cout << pow(2,a)-1<<endl;
	Hanoi(a, 1, 2, 3);
}