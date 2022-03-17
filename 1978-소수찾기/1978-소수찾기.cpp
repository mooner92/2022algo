#include <iostream>
#include <cmath>
using namespace std;
int t[1001];

void era(){
    int num=1000;
	int cnt = 0;
	int arr[10000];
	//scanf("%d", &num);

	for (int i = 2; i <= num; i++)
	{
		//arr[i] = i;
        t[i] = i;
	}

	for (int i = 2; i < sqrt(num); i++)
	{
		if (/*arr[i]*/t[i] == 0) continue;    // 0이면 건너뛰고 아니면 실행
		for (int j = 2 * i; j <= num; j += i)
		{
			//arr[j] = 0;
            t[j] = 0;
		}
	}

	/*for (int i = 2; i <= num; i++)
	{
		if (arr[i] != 0) printf("%d ", arr[i]);
	}*/
}

int main(){
    int tc,total=0;
    cin>>tc;
    era();
    for(int i=0;i<tc;i++){
        int q;
        cin>>q;
        if(t[q]!=0){
            total++;
        }
    }
    cout << total;
}
