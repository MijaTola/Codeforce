#include <bits/stdc++.h>

using namespace std;

long long n,k;
long long v[200010];

map<pair<unsigned long long, unsigned long long>, int> mp;

unsigned long long getPow(int num) {
    unsigned long long p = 1;
    for (int i = 0; i < num; ++i) {
        p *= 10LL;
    }
    return p;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    unsigned long long p = 10LL;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < n; ++j) {
            unsigned long long cur = (p * v[j]) % k;
            mp[make_pair(p, cur)]++;
        }
        p *= 10;
    }
    unsigned long long ans = 0;
    for (int i = 0; i < n; ++i) {
        unsigned long long dig = (unsigned long long)log10(v[i]) + 1;
        unsigned long long p = getPow(dig);
        unsigned long long cmod = (v[i] % k);
        cmod = ((k - cmod) + k) % k;
        ans += mp[make_pair(p, cmod)];
        if((v[i] * p) % k == cmod) ans--;
        
    }

    cout << ans << "\n";
    return 0;
}


