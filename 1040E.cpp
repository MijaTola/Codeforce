#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n,m;
long long k;
int parent[500010];
int sz[500010];
long long c[500010];

map<long long, vector<pair<int,int> > > mp;

void init() {
    for (int i = 0; i < 500010; ++i) 
        parent[i] = i;
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(x)] = find(y);
    sz[find(y)] += sz[find(x)];
}

int main() {

    auto modpow = [] (int a, long long b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };

    scanf("%d %d %lld", &n, &m, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", c + i);

    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        long long xo = c[x] ^ c[y];
        mp[xo].push_back({x,y});
    }
    init();

    long long ans = 0;
    for (auto p: mp) {

        auto &v = p.second;
        set<int> s;
        for (auto p2: v) {
            int x = p2.first;
            int y = p2.second;
            s.insert(x);
            s.insert(y);
            if(find(x) != find(y)) 
                merge(x,y);
        }

        int comp = 0;
        for (auto x: s) {
            if(x == find(x)) {
                comp++;
            }
            parent[x] = x;
        }
    
        int total = n - s.size() + comp;
        ans += modpow(2, total);
        ans %= mod;
    }
    long long dk = (modpow(2, k) - 1 + mod) % mod;
    ans += (modpow(2, n) * ((dk - mp.size() + 1 + mod) % mod) % mod);
    printf("%lld\n", ans % mod);
    return 0;
}

