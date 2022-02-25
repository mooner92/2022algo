#include <iostream>
using namespace std;

int main(){
    int a,b,c,m1,m2;
    cin >>a>>b>>c;
    m1=max(a,b);
    m2=max(m1,c);
    if(a==b&&b==c){cout << 10000+(a*1000);}
    else if(a==b&&b!=c){cout << 1000+(a*100);}
    else if(a!=b&&b==c){cout << 1000+(b*100);}
    else if(a!=b&&b!=c&&a==c){cout << 1000+(a*100);}
    else if(a!=b&&b!=c){cout << m2*100;}
    
}


/*#include<stdio.h>
int main(){int a,b,c;scanf("%d %d %d",&a,&b,&c);
    printf("%d",a==b&&a==c?10000+a*1000:a==b||a==c?1000+a*100:b==c?1000+b*100:a>b?a*100:b>c?b*100:c*100);
} */
/* C언어의 삼항 연산자로 풀이함 a ? 10 : 100   >>>>>> a가 참이면 10 거짓이면 100을 삽입 */

