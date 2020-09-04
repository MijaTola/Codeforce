#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int dp[200010][5];
int main() {
    
    auto op = [](int a, int b, int k) {
        if(!k) return min(a,b);
        return max(a,b);
    };
    
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    sort(v, v + n + 1);
    
    auto f = [&op] (int type) {
        
        for (int i = 0; i < 200010; ++i)
            for (int j = 0; j < 5; ++j)
                dp[i][j] = type ? 0 : 1e9;
    
        for (int i = 1; i < 4; ++i)
            dp[n + 1][i] = 0;

        for (int i = n; i >= 1; i--) {
            for (int j = 1, t = -1; j <= 3; ++j, t++) {
                int last = v[i - 1] + t;
                for (int k = 1, s = -1; k <= 3; ++k, s++) {
                    int cur = v[i] + s;
                    if(last < cur)
                        dp[i][j] = op(dp[i][j], dp[i + 1][k] + 1, type);

                    if(last == cur)
                        dp[i][j] = op(dp[i][j], dp[i + 1][k], type);
                }
            }
        }
        return dp[1][1];
    };

    cout << f(0) << " " << f(1) << "\n";
    return 0;
}

