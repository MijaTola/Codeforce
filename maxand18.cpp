#include <bits/stdc++.h>

using namespace std;

int n,x;
int c[35];
long long dp[35][35];

long long f(int pos, int cur) {
    if(pos < 0)  {
        if(cur == x) return 0;
        return -1e15;
    }
    
    long long &ans = dp[pos][cur];

    if(ans != -1) return ans;

    ans = -1e15;;
    
    ans = max(ans, f(pos - 1, cur + 1) + 1LL * c[pos] * (1LL << pos));
    ans = max(ans, f(pos - 1, cur));
    return ans;
}

long long ans;

void r(int pos, int cur) {
    if(pos < 0) return;
    
    if(f(pos -  1, cur) >= f(pos - 1, cur + 1) + 1LL * c[pos] * (1LL << pos)) {
        r(pos - 1, cur);
    } else {
        ans |= (1LL << pos);
        r(pos - 1, cur + 1);
    }
}

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> x;
        memset(c, 0, sizeof c);
        memset(dp, -1, sizeof dp);
        ans = 0;
        for (int i = 0; i < n; ++i) {
            int y;
            cin >> y;
            for (int i = 0; i < 32; ++i) 
                if(y & (1 << i)) c[i]++;
        }

        f(32,0);
        r(32,0);
        cout << ans << "\n";
    }
    return 0;
}

