#include <bits/stdc++.h>

using namespace std;

int t,n,m;
int c[12][2010];
int dp[2010][(1 << 12) + 10];
int f(int pos, int mask) {
    if(pos == m) 
        return (mask == (1 << n) - 1 ) ? 0 : -10;
    
    
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans = 0;

    for (int ini = 0; ini < n; ++ini) {
        for (int p = 0; p < (1 << n); ++p) {
            int sum = 0;
            bool flag = 1;
            for (int i = 0; i < n; ++i) {
                if(mask & (1 << i) and (p & (1 << ((i + ini) % n)))) 
                    flag = 0;
                else if(p & (1 << (i + ini) % n)) sum += c[(i + ini) % n][pos];
            }
            if(flag) {
                int cur = mask;
                for (int i = 0; i < n; ++i) {
                    if(p & (1 << (i + ini) % n)) 
                        cur |= (1 << i);

                }
                ans = max(ans, f(pos + 1, cur) + sum);
            }
            
        }
    }
    ans = max(ans, f(pos + 1, mask));
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];
        
        cout << f(0,0) << "\n";

    }
    return 0;
}

