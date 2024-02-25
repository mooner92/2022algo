#include <stdio.h>

int main() {
    int n,m,cnt=0;
    char a;
    int st[12];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&a);
        if(48<=a&&57>=a){
            st[cnt]=a-'0';
            cnt++;
            }
        else if(a=='+'){
            st[cnt-2]=st[cnt-2]+st[cnt-1];
            cnt--;
            }
        else if(a=='-'){
            st[cnt-2]=st[cnt-2]-st[cnt-1];
            cnt--;
        }
        else if(a=='*'){
            st[cnt-2]=st[cnt-2]-st[cnt-1];
            cnt--;
        }
        else if(a=='/'){
            st[cnt-2]=st[cnt-2]-st[cnt-1];
            cnt--;
        }
    }
    printf("%d",st[cnt]);
    return 0;
}