#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353; 
string s;
int n,k;
pair<long long, long long> dp[20][2][2][1 << 11];
long long power[20];
pair<long long, long long> f(int pos, int flag, int lead, int mask) {
    if(pos == n) return { 0, __builtin_popcount(mask) <= k};
    if(dp[pos][flag][lead][mask].first != -1) return dp[pos][flag][lead][mask];
    int ans = 0;
    int cnt = 0;
    int limit = 9;
    if(flag) limit = s[pos] - '0';
    for (int i = 0; i <= limit; ++i) {
        if(i == limit and flag) {
            pair<long long, long long> p;
            if(i == 0) {
                if(lead) p = f(pos + 1, 1, 1, mask);
                else p = f(pos + 1, 1, 1, mask | (1 << i));
            } else p = f(pos + 1, 1, 0, mask | (1 << i));

            cnt = (cnt + p.second) % mod;
            long long num = (((i * power[n - pos - 1]) % mod) * p.second) % mod;
            ans = (((num + p.first) % mod) + ans) % mod;

        } else {
            pair<long long, long long> p;
            if(i == 0) {
                if(lead) p = f(pos + 1, 0, 1, mask);
                else p = f(pos + 1, 0, 1, mask | (1 << i));
            } else p = f(pos + 1, 0, 0, mask | (1 << i));
            cnt = (cnt + p.second) % mod;
            long long num = (((i * power[n - pos - 1]) % mod) * p.second) % mod;
            ans = (ans + (num + p.first) % mod) % mod;
        }
    }
    return dp[pos][flag][lead][mask] = {ans,cnt};
}

int main() {

    long long p = 1;
    for (int i = 0; i <= 18; ++i) {
        power[i] = p;
        p = (p * 10) % mod;
    }
    long long l,r;
    cin >> l >> r >> k;
    l--;
    s = to_string(l);
    n = s.size();
    memset(dp, -1, sizeof dp);
    long long dl = f(0,1,1, 0).first;
    s = to_string(r);
    n = s.size();
    memset(dp, -1, sizeof dp);
    long long dr = f(0,1,1, 0).first;
    cout << ((dr - dl) + mod) % mod << "\n";
    return 0;
}

