#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        v.emplace_back(x,y);
    }

    map<pair<long long, long long> , set<long long> > mp;

    long long ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            long long y = v[j].second - v[i].second;
            long long x = v[j].first - v[i].first;
            int sg = 1;
            if(x * y < 0) sg = -1;
            y = abs(y);
            x = abs(x);
            if(x == 0) {
                long long k = v[j].first;
                mp[{LLONG_MAX, x}].insert(k);
            } else {
                int g = __gcd(x,y);
                x /= g, y /= g;
                y *= sg;
                long long c = x * v[j].second - y * v[j].first;
                mp[{y, x}].insert(c);
            }
        }

    long long total = 0;
    for (auto p: mp) {
        total += p.second.size();
    }

    ans = total * (total - 1) / 2;
    for (auto p: mp) {
        ans -= 1LL * p.second.size() * (p.second.size() - 1) / 2;
    }

    printf("%lld\n", ans);
    return 0;
}

