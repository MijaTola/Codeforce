#include <bits/stdc++.h>

using namespace std;

vector<string> v;
const long long mod = 998244353;

long long f(string x, string y) {
    int a = x.size() - 1;
    int b = y.size() - 1;
    string ans = "";
    while(a >= 0 or b >= 0) {
        if(b >= 0) ans += y[b--];
        if(a >= 0) ans += x[a--];
    }
    reverse(ans.begin(), ans.end());
    long long cur = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
        long long val = ans[i] - '0';
        cur = (cur * 10LL + val) % mod;
    }
    return cur % mod;
}
int main() {
    map<int,int> mp;
    int n;
    cin >> n;
    for (int i = 0; i< n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        mp[s.size()]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto p: mp) {
            string y = "";
            for (int j = 0; j < p.first; ++j)
                y += "0";
            long long cur = (f(v[i], y) * p.second) % mod;
            ans = (ans + cur) % mod;
            cur = (f(y, v[i]) * p.second) % mod;
            ans = (ans + cur) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}

