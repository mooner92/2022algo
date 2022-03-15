#include <iostream>
using namespace std;

struct queue
{
    int arr[10001];
    int l;

    void init(){
        l = -1;  //l을 -1로 지정
    }
    void push(int d){
        arr[++l] = d;
    }
    

};

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        
    }
}