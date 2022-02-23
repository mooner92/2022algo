#include <iostream>
using namespace std;

int main(){
    int hour,min,sec,cook = 0;
    cin >>hour>>min>>sec;
    cin >> cook;
    sec+=cook;
    if(sec>=60){min+=sec/60; sec%=60;} //60보다 크면 60으로 나눈 몫을 넘기고 나머지를 남김
    if(min>=60){hour+=min/60; min%=60;} // ""
    if(hour>=24){hour-=24;} //24보다 크면 24를 빼줌
    cout <<hour<<" "<<min<<" "<<sec;

}