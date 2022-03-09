#include <iostream>
using namespace std;
 
int factorial(int t) {
    int ans = 1;
    for (int i = t; i > 0; i--) {
        ans *= i;
    }
    return ans;
} //#for문이 재귀보다 빠름###
 
int main() {
    int n, k;
    cin >> n >> k;
 
    int result = factorial(n) / (factorial(k) * factorial(n - k));
 
    cout << result;
}