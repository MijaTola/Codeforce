#include <bits/stdc++.h>

using namespace std;

int n;

int v[3010];
int c[3010];
long long dp[3010][4];
long long f(int pos, int cur) {
    if(cur == 3) return 0;
    if(pos == n) {
        if(cur == 3) return 0;
        return 1e9;
    }
    if(dp[pos][cur] != -1) return dp[pos][cur];
    long long ans = 1e9;

    for (int i = pos; i < n; ++i) {
        if(v[pos - 1] < v[i]) 
            ans = min(ans,f(i + 1,cur + 1) + c[i]);
    }
    return dp[pos][cur] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    int ans = f(0,0);
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

