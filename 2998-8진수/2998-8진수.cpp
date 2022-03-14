#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string binary;
    cin >> binary;
 
    int l = binary.length();
    int t = 1;
    while(true) {
        if (t > l) break;
        t += 3;
    }
 
    string zero = "";
    for (int i = 1; i < t - l; i++) {
        zero += '0';
    }
    binary = zero + binary;
    
    string octal = "";
    string cutStr = "";
    string toOctal = "";
    int cutCount = t / 3;
    int start = 0;
    for (int i = 0; i < cutCount; i++, start+=3) {
        cutStr = binary.substr(start, 3);
        toOctal = (cutStr[0] - '0') * 4 + (cutStr[1] - '0') * 2 + cutStr[2];
        //cout << toOctal << endl;
        octal += toOctal;
    }
 
    cout << octal;
 
    return 0;
}
