#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    vector<int> a;
    vector<int> b;
    int sum=0;
    int sum1=0;
    for(int i=0;i<6;i++){
        int t;
        cin>>t;
        if(i<4){
            a.push_back(t);
            sum1+=t;
        }
        else
            b.push_back(t);
    }
    sum+=(max(b[0],b[1]))+(sum1-(min(min(a[0],a[1]),min(a[2],a[3]))));
    //sum = min({a[0],a[2],a[3],a[4]});    이게 되네
    cout <<sum;

}