#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int dia,hr,wr;
    double o=0.0;
    cin>>dia>>hr>>wr;
    o = sqrt(pow(dia,2)/(pow(hr,2)+pow(wr,2)));
    cout << floor(o*hr) <<" "<< floor(o*wr);
}