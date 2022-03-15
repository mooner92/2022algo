#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

queue<int> getPrime(int q, int w){  //queue를 반환하는 함수 getprime을 작성
    int n=q,m=w; //e값과 r값
	int arr1[1000001];  //q까지의 값을 모두 담을 배열을 생성
    int arr2[1000001];  //W까지의 값을 모두 담을 배열을 생성
    queue<int> k1;  //n의소수들만 푸시백할 큐 생성
    queue<int> k2;  //m의소수들만 푸시백할 큐 생성
    //queue<int> ans; //answer 큐 생성

	for (int i = 2; i <= n; i++)
	{
		arr1[i] = i;  //배열에 담음
	}

	for (int i = 2; i < sqrt(n); i++)
	{
		if (arr1[i] == 0) continue;    // 0이면 건너뛰고 아니면 실행
		for (int j = 2 * i; j <= n; j += i)
		{
			arr1[j] = 0;  //소수를 제외한 나머지를 0으로 치환
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr1[i] != 0) k1.push(arr1[i]);
	}
    
    //여기까지 n(e)에대한 소수를 구해 배열에 저장했음 (소수가 아닌 부분은 0이 대입되어있음)
    ////////////////////////////////////////////////////////////////////
    for (int i = 2; i <= m; i++)
	{
		arr2[i] = i;  //배열에 담음
	}

	for (int i = 2; i < sqrt(m); i++)
	{
		if (arr2[i] == 0) continue;    // 0이면 건너뛰고 아니면 실행
		for (int j = 2 * i; j <= m; j += i)
		{
			arr2[j] = 0;  //소수를 제외한 나머지를 0으로 치환
		}
	}

	for (int i = 2; i <= m; i++)
	{
		if (arr2[i] != 0) k2.push(arr2[i]);
	}
    //여기까지 m(w)에대한 소수를 수해 배열에 저장했음 (소수가 아닌 부분은 0이 대입되어있음)
    
    //여기서부터 두 벡터를 비교하여 k2 큐 를구현
    

    while(!(k1.size()==0)){
        if(k1.front()==k2.front()){
            if(k1.front()>=n){
                break;
            }
            else{
                k1.pop();
                k2.pop();
                
            }
            
        }
    }
    /*for(int i=0;i<k1.size()-1;i++){ //작은큐의 사이즈-1까지의 루프를 돌려서 큰 큐에서 제거
        if(k1.front()==k2.front()){
            k2.pop();
        }
    }*/
    
    
    return k2;  //k2큐를  반환
}

int main(){
    int e,r;
    cin>>e>>r;   //e와 r을 받음
    //int arr[1000001];
    queue<int> arr3 = getPrime(e,r);  //arr과 e와 r을 이용하여 e와 r사이의 소수를 구하는 getPrime 함수를 호출
    while(!arr3.empty()){
        cout<<arr3.front()<<"\n";
        arr3.pop();
    }
}

/*for(int i=0;i<k2.size();i++){
        //cout << k1.size()<<"\n";
        //cout << arr1[i]<<"\n";
        //cout <<k2.size()<<"\n";
        cout <<k2.front()<<"\n";
        k2.pop();
    }*/