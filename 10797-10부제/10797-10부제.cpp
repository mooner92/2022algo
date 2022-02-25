#include <iostream>
using namespace std;

int main(){
    int num,count=0;
    cin >> num;
    int arr[5];
    for(int i=0;i<5;i++){cin >> arr[i]; if(arr[i]==num){count++;}}
    cout << count;
}