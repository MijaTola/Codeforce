#include <bits/stdc++.h>

using namespace std;

int n;
string s;
const int mod = 998244353;
bool ver[26];
int dp[200010][4][27];

int f(int pos, int flag, int letter) {
    if(pos == n) return flag >= 1;
    int &ans = dp[pos][flag][letter];
    if(ans != -1) return ans;
    ans = 0;
    if(flag == 0) {
        ans = (ans + f(pos + 1, 1, letter)) % mod;
        if(letter == s[pos] - 'a')
            ans = (ans + f(pos + 1, flag, letter)) % mod;
    }
    if(flag == 1) {
        ans = (ans + f(pos + 1, flag, letter)) % mod;
        if(letter == s[pos] - 'a')
            ans = (ans + f(pos + 1, 2, letter)) % mod;
    }
    if(flag == 2) {
        if(letter == s[pos] - 'a')
            ans = (ans + f(pos + 1, flag, letter)) % mod;
    }
    return ans % mod;
}

int main() {
    memset(dp, -1,sizeof dp);
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        ver[s[i] - 'a'] = 1;
        cnt++;
    }

    long long ans = 0;
    for (int i = 0; i <= 26; i++)
        if(ver[i]) { 
            long long  a = f(0,0,i);
            if(a) a = ((a - 1) + mod) % mod;
            ans = (ans + a) % mod;
        }

    cout << ans + 1 << "\n";
    return 0;
}

