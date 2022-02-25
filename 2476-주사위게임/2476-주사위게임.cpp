#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a,b,c,repeat,ex1;
    cin >> repeat;
    vector <int> v1;
    for(int i=0;i<repeat;i++){
        cin >>a>>b>>c;
        ex1 = (a==b&&a==c)?10000+a*1000:(a==b||a==c)?1000+a*100:(b==c)?1000+b*100:(a>b)?a*100:(b>c)?b*100:c*100;
        v1.push_back(ex1);
    }
    sort(v1.begin(),v1.end());
    cout << v1.back();
    
}