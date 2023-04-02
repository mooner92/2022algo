#include <iostream>
using namespace std;
int njh[100001] = {0}; // nu juck hap
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tg = 0, n, m, sld[3];
    long long tss;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> njh[i];
        njh[i] += njh[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> sld[0] >> sld[1] >> sld[2];

        tss = njh[sld[0] - 1];

        // while (tss < sld[2]) tss += njh[n];  //시간초과 원인으로 추정 //승차시각
        if (sld[2] - tss > 0)
            tss += njh[n] * ((sld[2] - tss) / njh[n] + 1);

        if (sld[0] < sld[1])
            tss += njh[sld[1] - 1] - njh[sld[0] - 1];
        else
            tss += njh[n] - njh[sld[0] - 1] + njh[sld[1] - 1];
        tg = tg < tss ? tss : tg;
    }
    cout << tg;
}