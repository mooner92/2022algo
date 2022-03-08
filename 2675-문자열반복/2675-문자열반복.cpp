#include <iostream>
/*#include <string>
#include <vector>
using namespace std;
int main(){
    int tc;
    cin >>tc;
    for(int i=0;i<tc+1;i++){
        int p;
        string s;
        vector<char> l;
        getline(cin,s);   //앞에있는 getline이 뒤에있는 cout보다 늦게 실행되는 이유?
        p = s[0]-48;  //숫자 아스키코드 값을 계산해줌
        //cout << p <<endl;
        for(int j=2;j<p+2;j++){
            for(int h=0;h<p;h++){
                //cout <<s[j];
                l.push_back(s[j]);
            }
        }
        for (auto i = l.begin(); i != l.end(); ++i)
            cout << *i;
    }
}*/

#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int tc;
    cin >> tc;
    for(int i = 0;i < tc;i++)
    {
        int r;
        string p;
        cin >> r;
        cin >> p;
 
        for(int j = 0;j < p.length();j++)
        {
            for(int k = 0;k < r;k++)
            {
                cout << p[j];
            }
        }
        cout << endl;
    }
    return 0;
}

    

