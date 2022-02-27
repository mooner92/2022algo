#include <iostream>
using namespace std;

int main(){
    int repeat;
    cin >> repeat;
    int remainsum=0;
    for(int i=0;i<repeat;i++){
        int apple,stu;
        cin >>stu>>apple;
        remainsum+=(apple%stu);
    }
    cout << remainsum;
}