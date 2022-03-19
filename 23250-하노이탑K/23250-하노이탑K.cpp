#include <iostream>
#include <vector>
using namespace std;
//using ll = long long;
vector<pair<int,int>> k;
void Hanoi(int n, int from, int via, int to) 
{
	// 재귀함수는 반드시 끝나는 조건이 있어야 한다
    
	if (n == 1) {
		//cout << from << " -> " << to << endl;
        k.push_back(make_pair(from,to));
	}

	else {
		Hanoi(n - 1, from, to, via);
		//cout << from << " -> " << to << endl;
        k.push_back(make_pair(from,to));
		Hanoi(n - 1, via, from, to);
	}
}

int main()
{
    int q,w;
    cin>>q>>w;
	Hanoi(q, 1, 2, 3);
    cout << k[w-1].first <<" "<< k[w-1].second;
}