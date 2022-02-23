#include <iostream>
using namespace std;

int main(){
    int hour,minute,cook =0;

    cin >> hour >> minute;
    cin >> cook;
    minute = cook+minute;
    hour += minute/60;
    if(hour>=24){hour-=24;}
    cout << hour << " " << minute%60;

}