#include <bits/stdc++.h>

using namespace std;

string s;
bool is[1 << 21];
int dp[22][1 << 21];
int f(int pos, int mask) {
    if(pos == 20) return is[mask] ? __builtin_popcount(mask) : 0;
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans = 0;
    ans = max(ans, f(pos + 1, mask));
    if(mask & (1 << pos)) ans = max(ans, f(pos + 1, mask ^ (1 << pos)));
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int j = i; j >= max(0, i - 20); j--) {
            int c = s[j] - 'a';
            if(mask & (1 << c)) break;
            mask |= (1 << c);
            is[mask] = 1;
        }
    }
    
    int ans = 0;
    for (int mk = 0; mk < (1 << 20); mk++) {
        if(!is[mk]) continue;
        ans = max(ans, f(0, ((1 << 20) - 1) ^ mk) + __builtin_popcount(mk));
    }
    cout << ans << "\n";
    return 0;
}

