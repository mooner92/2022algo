#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    int n,k,sum=0;
    cin >> n>>k;
    int sumarray[n*2];//원소 k개의 합을 칸마다 저장하는 배열 생성
    int array[2*n];
    for(int i=0;i<n;i++){
        int k;
        cin >>k;
        array[i]=k;
        array[i+n]=k;    //배열 두개를 이은 배열을 생성 ex:) [1,2,3,4] ===>> [1,2,3,4,1,2,3,4]
    }
    int arrsize = sizeof(array)/sizeof(int);

    /*for(int i=0;i<2*n;i++){
        cout << array[i] << endl;
    }*/
    int dummy=0;
    for(int i=0;i<arrsize;i++){
        for(int j=0;j<k;j++){
           
           if(i+j<arrsize){
               dummy+=array[i+j];
               sumarray[i]=dummy;
           }
           if(j==(k-1)){
               dummy=0;
           }
        }
        //cout << sumarray[i] <<endl;
    }
    sort(sumarray,sumarray+(arrsize));

    
    
    /*for(int i=0;i<arrsize;i++){
        cout << sumarray[i] << endl;
    }*/
    cout << sumarray[arrsize-1];
    

    // sumarray[i]+=array[i+j];

    //cout << sum;
}