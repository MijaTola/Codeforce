#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n,m;
    scanf("%lld %lld", &n, &m);
        
    if(m >= n) {
        cout << n << "\n";
        return 0;
    }
    long long a = -1, b = 1e10;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        long long current = (m + 1) + mid;
        long long having = n - (mid * (mid + 1)) / 2;
        if(having - current >= 0) a = mid;
        else b = mid;
    }
    long long ans = a + m + 1;

    long long having = n - (a * (a + 1)) / 2;
    ans += ans < having;
    
    printf("%lld\n", ans);
    return 0;
}

