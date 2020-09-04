#include <bits/stdc++.h>

using namespace std;

int n;
long long v[200010];
long long sum[200010];

struct line {
    long long m,b;
    line() {}
    line(long long _, long long __) {
        m = _, b = __;
    }
    long long get(long long x) {
        return m * x + b;
    }
};

struct cht {
    vector<line> trick;
    int pos;
    cht() { pos = 0;}
    bool irrelevant(line l1, line l2, line l3) {
        return (l3.b - l1.b) * (l1.m - l2.m) <= (l2.b - l1.b) * (l1.m - l3.m);
    }
    
    void add(line l) {
        while(trick.size() >= 2 
          and irrelevant(trick[trick.size() - 2], trick[trick.size() - 1], l))
            trick.pop_back();
        trick.push_back(l);
    }

    long long query(long long x) {
        int a = -1; 
        int b = trick.size() - 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(trick[mid].get(x) <= trick[mid + 1].get(x)) a = mid;
            else b = mid;
        }
        return trick[b].get(x);
    }
};

int main() {
    scanf("%d", &n);

    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", v + i);
        cur += v[i] * i;
        sum[i] = v[i];
    }
    for (int i = 1; i <= n; ++i) 
        sum[i] += sum[i - 1];
    
    long long ans = -1e18;

    cht ct,ct1;

    for (int i = n; i >= 1; i--) {
        ct.add(line(- i, -sum[i]));
        long long q = ct.query(-v[i]);
        q += sum[i] - v[i] * (long long)i;
        ans = max(ans,q);
    }

    for (int i = 1; i <= n; ++i) {
        ct1.add(line(i, -sum[i - 1]));
        long long q = ct1.query(v[i]);
        q += sum[i - 1] - v[i] * (long long)i;
        ans = max(ans, q);
    }
    printf("%lld\n", ans + cur);
    return 0;
}

