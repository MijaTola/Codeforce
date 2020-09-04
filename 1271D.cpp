#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int dp[5010][10010];
int a[5010] ,b[5010], c[5010], to[5010];
vector<int> path[5010];

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", a + i, b + i, c + i);
        to[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        to[y] = max(to[y], x);
    }

    for (int i = 0; i < n; ++i) 
        if(to[i] >= 0) path[to[i]].push_back(c[i]);

    for (int i = 0; i < n; ++i) 
        sort(path[i].rbegin(), path[i].rend());
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < 7010; ++j)
            dp[i][j] = -1e9;
    

    for (int i = 0; i < 7010; ++i)
        dp[n][i] = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 7010; ++j) {
            if(a[i] > j) continue;
            int sum = 0;
            for (int k = 0, cur = 1; k < (int)path[i].size(); ++k, cur++) {
                sum += path[i][k];
                if(j + b[i] - cur >= 0) dp[i][j] = max(dp[i][j], dp[i + 1][j + b[i] - cur] + sum);
            }
            dp[i][j] = max(dp[i][j], dp[i + 1][j + b[i]]);
        }
    }

    printf("%d\n", max(-1, dp[0][k]));
    return 0;
}

