#include <bits/stdc++.h>

using namespace std;

int p[1000100];

void init() {
    for (int i = 0; i < 100000; ++i)
        p[i] = i;
}

int find(int u) {
    return (u == p[u]) ? u : p[u] = find(p[u]);
}

void merge(int x, int y) {
    p[find(y)] = find(x);
}

int main() {
    memset(p, 0, sizeof p);

    for (int i = 2; i * i < 1000100; ++i) {
        for (int j = i + i; j < 1000100; j += i)
            p[j] = 1;
    }
    vector<int> pr;
    map<long long, int> mp;
    for (int i = 2; i < 1000100; i++) {
        if(!p[i]) {
            pr.push_back(i);
            mp[i] = i;
        }
    }

    for (long long x: pr) {
        long long p = x * x;
        while(p <= 1e12) {
            if(p == 0) return 0;
            mp[p] = x;
            p *= x;
        }
    }

    long long n;
    cin >> n;
    if(mp.count(n)) return cout << mp[n] << "\n", 0;

    bool flag = 0;
    for (long long i = 2; i * i <= n; ++i) {
        flag |= (n % i == 0);
    }
    if(flag) cout << "1\n";
    else cout << n << "\n";
    return 0;
}

