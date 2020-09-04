#include <bits/stdc++.h>

using namespace std;

int n,m;
set<long long> is;
map<long long, long long > ans;
vector<int> v,t;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; ++i) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    for (int i = 0; i < n + m; ++i) {
        int x;
        scanf("%d", &x);
        if(x == 1) {
            t.push_back(v[i]);
            is.insert(v[i]);
        }
    }
    for (int i = 0; i < n + m; ++i) {
        if(is.count(v[i])) continue;
        long long pos = lower_bound(t.begin(),t.end(), v[i]) - t.begin();
        long long d1 = t[pos];
        long long d2 = -100000000LL;
        if(pos - 1 >= 0) d2 = t[pos - 1];
        if(abs(d2 - v[i]) <= abs(d1 - v[i]) and pos - 1 >= 0) ans[t[pos - 1]]++;
        else ans[t[pos]]++;
    }

    for (int i = 0; i < (int)v.size(); ++i)
        if(is.count(v[i])) printf("%lld ", ans[v[i]]);
    puts("");
    return 0;
}

