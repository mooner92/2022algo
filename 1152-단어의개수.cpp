#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string ex1;
    getline(cin,ex1);
    int spacecount = 0;
    if(ex1[0] == ' ')
        spacecount--;

    if(ex1[ex1.length()-1] == ' ')
        spacecount--; 

    for(int i=0;i<ex1.length();i++){

        if (ex1[i] == ' ')
        spacecount++;

        
    }

    cout << spacecount+1;
}