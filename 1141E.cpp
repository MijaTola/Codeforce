#include <bits/stdc++.h>

using namespace std;

int v[200010];

int main() {
    long long h;
    int n;
    cin >> h >> n;

    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    
    long long a = 0;
    long long b = 1e12 + 1;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(h + (mid * sum) <= 0) b = mid;
        else a = mid;
    }
    
    if(b == 1e12 + 1) return cout << "-1\n", 0;
    

    long long ans = n * (b - 1);
    long long cur = sum * (b - 1);
    
    int i;
    for (i = 0; i < n; ++i) {
        cur += v[i];
        if(cur >= h) break;
    }
    cout << ans + i << "\n";
    return 0;
}

