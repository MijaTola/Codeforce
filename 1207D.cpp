#include <bits/stdc++.h>

using namespace std;

int n;
long long f[300010];
const long long mod = 998244353LL;
vector<pair<int,int> > v,b;

int main() {
    f[0] = 1;
    for (int i = 1; i < 300010; ++i)
        f[i] = ((long long)i * f[i - 1]) % mod;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        v.push_back({x,y});
        b.push_back({y,x});
    }
    

    sort(v.begin(), v.end());
    sort(b.begin(), b.end());

    long long a1 = 1, a2 = 1, a3 = 1;
    int last = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(last == v[i].first) cnt++;
        else {
            a1 = (a1 * f[cnt]) % mod;
            cnt = 1;
        }
        last = v[i].first;
    }

    a1 = (a1 * f[cnt]) % mod;
    last = -1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(last == b[i].first) cnt++;
        else {
            a2 = (a2 * f[cnt]) % mod;
            cnt = 1;
        }
        last = b[i].first;
    }
    a2 = (a2 * f[cnt]) % mod;
    
    auto l = v[0];
    cnt = 1;

    for (int i = 1; i < n; ++i) {
        if(b[i].second < b[i - 1].second) a3 = 0;
        if(l == b[i]) cnt++;
        else {
            a3 = (a3 * f[cnt]) % mod;
            cnt = 1;
        }
        l = b[i];
    }

    a3 = (a3 * f[cnt]) % mod;

    long long ans = (f[n] + a3) % mod;;
    ans = (ans + mod - a1) % mod;
    ans = (ans + mod - a2) % mod;
    printf("%lld\n", ans);
    return 0;
}

