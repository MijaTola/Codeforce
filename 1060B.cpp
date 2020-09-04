#include <bits/stdc++.h>

using namespace std;


int main() {
    
    long long n;
    scanf("%lld", &n);

    long long b = 0;
    int sum = 0;
    while(b <= n) {
        b = b * 10 + 9;
        sum += 9;
    }
    b /= 10;
    sum -= 9;
    
    long long res = n - b;

    while(res > 0) {
        sum += res % 10;
        res /= 10;
    }
    printf("%d\n", sum);
    return 0;
}

