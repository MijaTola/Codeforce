#include <bits/stdc++.h>

using namespace std;

long long m;
long long ver(long long n) {
    long long ans = 0LL;
    for (long long i = 2; i * i * i <= n; ++i) 
        ans += n / (i * i * i);
    return ans;
}

int main() {
    long long a = -1, b = 1e16 + 1;
    cin >> m;
    while(b - a > 1) {
        long long mid = (a + b) / 2LL;
        if(ver(mid) >= m) b = mid;
        else a = mid;
    }
    if(ver(b) != m) return cout << "-1\n",0;
    cout << b << "\n";
    return 0;
}

