#include <iostream>
#include <string>
using namespace std;

int main(){
    string x;
    getline(cin,x);
    cout << x.size() <<"\n";
    cout << x.length();     //같은 값이 나온다...
}