#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/

    int tc;
    cin>>tc;
    deque<int> l;
    for(int i=0;i<tc;i++){
        string s;
       
        cin>>s;
        if(s=="push_front"){
            int k;
            cin>>k;
            l.push_front(k);
        }
        else if(s=="push_back"){
            int k;
            cin>>k;
            l.push_back(k);
        }
        else if(s=="pop_front"){
            if(l.empty()){
                cout <<"-1\n";
            }
            else{
                int q;
                q = l.front();
                l.pop_front();
                cout <<q<<"\n"; 
            }
        }
        else if(s=="pop_back"){
            if(l.empty()){
                cout <<"-1\n";
            }
            else{
                int q;
                q = l.back();
                l.pop_back();
                cout <<q<<"\n";
            }
        }
        else if(s=="size"){
            cout <<l.size()<<"\n";
        }
        else if(s=="empty"){
            if(l.empty()){
                cout <<"1\n";
            }
            else 
                cout<<"0\n";
        }
        else if(s=="front"){
            if(l.empty()){
                cout <<"-1\n";
            }
            else{
                cout<<l.front()<<"\n";
            }
        }
        else if(s=="back"){
            if(l.empty()){
                cout <<"-1\n";
            }
            else{
                cout <<l.back()<<"\n";
            }
        }

    }
}