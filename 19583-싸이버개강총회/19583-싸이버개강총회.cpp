#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstdlib>
using namespace std;
int main()

{
    int ans = 0;
    vector<map<string, int>> v1(100000); // hash table 선언 size=2400  이름비교해줄 것
    string k[3] = {};
    vector<string> s;
    string str;
    while (getline(cin, str))
    {
        str.erase(find(str.begin(), str.end(), ':')); //:제거하여 저장
        s.push_back(str);
    }
    vector<string> search(s.size());

    istringstream stream1(s[0]);
    stream1 >> k[0] >> k[1] >> k[2];
    int starttime = stoi(k[0]);
    int endtime = stoi(k[1]);
    int streamend = stoi(k[2]); //시간 20:38을 2038의 정수로 저장

    for (int i = 2; i < s.size(); i++)
    {
        map<string, int>::iterator iter;
        string dummy2[2];
        istringstream ss(s[i]);
        ss >> dummy2[0] >> dummy2[1];
        int time = stoi(dummy2[0]);
        string name = dummy2[1];
        v1[i].insert({name, time}); // hash table 구성

        if (v1[i].size() == 2)
        { //값이 두개 = 퇴장이 입력되었을 경우
            if (v1[i].begin()->second <= starttime && (v1[i].end()->second >= endtime && v1[i].end()->second <= streamend))
            {
                ans++;
            }
        }
    }
    cout << ans;
}
