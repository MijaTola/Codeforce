#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
long long f[401000];

int main() {
    
    f[0] = 1;
    for (int i = 1; i < 401000; ++i)
        f[i] = (i * f[i - 1]) % mod;
 
    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b > 0) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };
 
    auto C = [modpow] (int n, int k) -> long long {
        if(k > n) return 0;
        long long num = f[n];
        long long den = (f[n - k] * f[k]) % mod;
        return (1LL * num * modpow(den, mod - 2)) % mod;
    };


    int n,k;
    cin >> n >> k;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int l,r;
        cin >> l >> r;
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    
    priority_queue<int> q;

    for (int i = 0; i < n; ++i) {
        int l = v[i].first, r = v[i].second;
        
        while(!q.empty() and -q.top() < l) {
            q.pop();
        }
        ans += C(q.size(), k - 1);
        ans %= mod;
        q.push(-r);
    }

    cout << ans << "\n";
    
    return 0;
}

