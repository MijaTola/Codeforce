#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
string s;
long long v[100010];
long long b[100010];
long long c[100010];

int main() {

    cin >> s;

    long long cur = 0;
    long long power = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        v[i] = (power * (s[i] - '0')) % mod + cur;
        v[i] %= mod;
        power *= 10;
        power %= mod;
        cur = v[i];
    }

    b[0] = s[0] - '0';
    for (int i = 1; i < (int)s.size(); ++i) {
        b[i] = (b[i - 1] * 10) % mod + (s[i] - '0');
        b[i] %= mod;
    }
   
    int n = s.size();
    
    long long p = 1;

    for (int i = n - 1; i >= 0; i--) {
        v[i] += v[i + 1];
        v[i] %= mod;
        c[i] = p;
        c[i] += c[i + 1];
        c[i] %= mod;
        p *= 10;
        p %= mod;
    }
    
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += b[i] * c[i + 1];
        ans %= mod;
        ans += v[i + 2]; 
        ans %= mod;
    }

    cout << (ans + v[1]) % mod << "\n";
    

    return 0;
}

