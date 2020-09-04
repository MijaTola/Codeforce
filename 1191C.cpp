#include <bits/stdc++.h>

using namespace std;

long long n, m, k;
set<long long> s;

int main() {

    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        long long x;
        scanf("%lld", &x);
        s.insert(x);
    }

    long long deleted = 0;
    int ans = 0;

    while(s.size() > 0) {
        ans++;
        long long total = n / k;
        long long a =  0, b = total + 1;
        long long cur = *s.begin();
        
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(mid * k + 1 <= cur - deleted) a = mid;
            else b = mid;
        }

        int cnt = 0;
        while(*s.begin() - deleted < (a + 1) * k + 1 and s.size() > 0) {
            s.erase(*s.begin());
            cnt++;
        }
        deleted += cnt;
    }
    printf("%d\n", ans);

    return 0;
}
