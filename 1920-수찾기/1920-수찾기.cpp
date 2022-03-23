#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//vector<string> k;
//vector<string> l;
string k[100001];
string l[100001];
int BSearchRecursive(int arr[], int target, int low, int high) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return BSearchRecursive(arr, target, low, mid-1);
    else
        return BSearchRecursive(arr, target, mid+1, high);
}

int main(){
    int n,m;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        //k.push_back(s);
        k[i] =  s;
    }  //벡터에 스트링 형태로 저장
    //sort(k.begin(),k.end());
    sort(k,k+(k->length()));
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        l[i] = s;
        for(int j=0;j<n;j++){
            //int r = BSearchRecursive(k,1,2,3);
        }
    }
    

}