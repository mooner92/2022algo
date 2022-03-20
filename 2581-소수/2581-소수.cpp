#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> u;
int sum=0;
void prime(int a,int b){
    int tem=a;
    int num=b;
	int arr[1000001];
    int isPrime[1000001] = {0};

	for (int i = 2; i <= num; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i < sqrt(num); i++)
	{
		if (arr[i] == 0) continue;    // 0이면 건너뛰고 아니면 실행
		for (int j = 2 * i; j <= num; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= num; i++)
	{
		if (arr[i] != 0) isPrime[i]=1;
	}
    for(int i=0;i<=num;i++){
        if(i>=a){
            if(isPrime[i]==1){
                u.push_back(arr[i]);
                sum+=arr[i];
                //cout<<arr[i]<<"\n";
        }
        }
        
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    prime(n,m);
    sort(u.begin(),u.end());
    if(u.size()==0){
        cout << "-1";
        return 0;
    }
    cout <<sum<<"\n"<<u.front();

}