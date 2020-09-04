#include <bits/stdc++.h>

using namespace std;

int f(int u) {
    if(u == 1 or u == 0) return 0;
    int ans = 0;
    ans = f(__builtin_popcount(u)) + 1;
    return ans;
}
string s;
int dp[1010][1010][2];
int k;
const int mod = 1e9 + 7;
int solve(int pos, int cur, int flag) {
    if(pos == (int)s.size()) {
        if(cur == 0 and k != 0) return 0;
        if(f(cur) + 1 == k) return 1;
        return 0;
    }
    if(dp[pos][cur][flag] != -1) return dp[pos][cur][flag];
    int ans = 0;
    if(flag) {
        for (int i = 0; i <= s[pos] - '0'; ++i) {
            if(i == s[pos] - '0')
                ans = (ans + solve(pos + 1, cur + (i == 1), 1)) % mod;
            else ans = (ans + solve(pos + 1, cur + (i == 1),0)) % mod;
        }
    }else {
        for (int i = 0; i <= 1; i++) 
            ans = (ans + solve(pos + 1, cur + (i == 1),0)) % mod;
        
    }

    return dp[pos][cur][flag] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> s >> k;
    if(k == 0) return puts("1");
    if(s == "1" and k == 1) return puts("0"),0;
    int ans = solve(0,0,1);
    if(k == 1) ans--;
    cout << ans << "\n";
    return 0;
}

