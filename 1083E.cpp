#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<pair<long long, long long>, long long> > v;

struct cht {
    vector<long long> a, b;

    double cross(int i, int j, int k) {
        return 1.d*(a[j] - a[i])*(b[k] - b[i]) - 1.d*(a[k] - a[i])*(b[j] - b[i]);
    }

    void add(long long da, long long db) {
        a.push_back(da);
        b.push_back(db);

        while (a.size() > 2 && cross(a.size() - 3, a.size() - 2, a.size() - 1) <= 0) {
            a.erase(a.end() - 2);
            b.erase(b.end() - 2);
        }
    }

    long long query(long long x) {
        if (a.empty()) return (long long)1e18;
        int l = 0, r = a.size() - 1;

        while (l < r) {
            int mid = l + (r - l) /2;
            long long f1 = a[mid] * x + b[mid];
            long long f2 = a[mid + 1] * x + b[mid + 1];
            if (f1 > f2) l = mid + 1;
            else r = mid;
        }

        return a[l]*x + b[l];
    }
};


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        long long a,b,c;
        scanf("%lld %lld %lld", &a,&b,&c);
        v.push_back({{a,b}, c});
    }

    sort(v.begin(), v.end());

    cht dp;
    dp.add(0,0);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long x = v[i].first.first;
        long long y = v[i].first.second;
        long long a = v[i].second;
        long long cur = x * y - a - dp.query(y);
        ans = max(ans, cur);
        dp.add(x , -cur);
    }
    printf("%lld\n", ans);
    return 0;
}

