#include <bits/stdc++.h>

using namespace std;

long long n,m;
long long ta,tb,k,x;
vector<long long> a,b;
long long ver(long long curTime, int dk) {
    int p = lower_bound(b.begin(), b.end(), curTime) - b.begin() + dk;
    if(p >= (int)b.size()) return -1;
    return b[p] + tb;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        cin >> x;
        b.push_back(x);
    }
    if(k == min(n,k)) return puts("-1"),0;
    long long ans = 0;
    for (int i = 0; i <= k; ++i) {
        long long cur = ver(a[i] + ta, k - i);
        ans = max(ans, cur);
        if(cur == -1) return cout << "-1\n",0;
    }
    cout << ans << "\n";
    return 0;
}
