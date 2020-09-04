#include <bits/stdc++.h>

using namespace std;

int n,x,m;
vector<int> v[9];
int b[1010];

int dp[1010][(1 << 8) + 1];

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);

    set<int> s;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        x--;
        b[i] = x;
        s.insert(x);
        v[x].push_back(i);
    }

    auto f = [] (int m) {
        for (int i = 0; i < 1010; ++i) {
            for (int j = 0; j < 256; ++j)
                dp[i][j] = -1e9;
            dp[i][255] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 256; ++j) {
                for (int k = 0; k < 8; ++k) {
                    if(!(j & (1 << k))) {
                        int p = lower_bound(v[k].begin(), v[k].end(), i) - v[k].begin();
                        int Next = p + m - 1;
                        if(0 <= Next and Next < (int)v[k].size())
                            dp[i][j] = max(dp[i][j], dp[v[k][Next] + 1][j | (1 << k)] + m);
                        
                        Next++;
                        if(0 <= Next and Next < (int)v[k].size())
                            dp[i][j] = max(dp[i][j], dp[v[k][Next] + 1][j | (1 << k)] + m + 1);

                    }
                }
            }
        }
        return dp[0][0];
    };
    
    int a = 0, b = n + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(f(mid) > 0) a = mid;
        else b = mid;
    }
    printf("%d\n", max((int)s.size(), f(a)));
    return 0;
}

