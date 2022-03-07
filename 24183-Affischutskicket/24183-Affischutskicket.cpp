#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    double a,b,c;
    cin >>a>>b>>c;
    a = a/1000000*229*324;
    b = b/1000000*297*420;
    c = c/1000000*210*297;
    printf("%.6f",(2*a)+(2*b)+c);
    
}