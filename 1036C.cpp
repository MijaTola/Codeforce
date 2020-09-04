#include <bits/stdc++.h>

using namespace std;

string s;
int sz;
int dp[30][30][2];

int f(int pos, int cnt, int flag) {
    if(pos == sz) {
        if(cnt <= 3) return 1;
        return 0;
    }
    if(dp[pos][cnt][flag] != -1) return dp[pos][cnt][flag];
    int ans = 0;
    int lim = 9;
    if(flag) lim = (int)(s[pos] - '0');
    for (int i = 0; i <= lim; ++i) {
        if(i == lim and flag) ans += f(pos + 1, cnt + (i != 0), 1);
        else ans += f(pos + 1, cnt + (i != 0), 0);
    }
    return dp[pos][cnt][flag] = ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(dp, -1,sizeof dp);
        long long x; cin >> x;
        x--;
        s = to_string(x);
        sz = s.size();
        int ans1 = f(0,0,1);
        memset(dp, -1,sizeof dp);
        cin >> s;
        sz = s.size();
        int ans2 = f(0,0,1);
        cout << ans2 - ans1 << "\n";
    }
    return 0;
}

