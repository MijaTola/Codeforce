#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long mx = 0;
    long long mn = 1e18;
    for (int i = 0; i <= n; ++i) {
        long long t = i;
        long long left = n - t;
        long long nd = t * (t - 1) / 2;
        if((t + 1) / 2 <= m  and m <= nd) {
            mn = min(mn,left);
            mx = max(mx,left);
        }
    }
    printf("%lld %lld\n", mn,mx);
    return 0;
}

