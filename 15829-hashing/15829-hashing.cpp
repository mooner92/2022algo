#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    string s;
    cin>>a;
    cin>>s;
    long long sum=0;
    for(int i=0;i<a;i++){
        sum+=((s[i]-96)*pow(31,i));
    }

    cout <<sum;

    

    
}
