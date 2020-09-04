#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,c;
vector<int> G[5010];
int vis[5010];
int total[5010];
int col[5010];
int dp[5010][5010];
int ans[5010];
vector<int> co[5010], no[5010];

bool f(int u, int bi, int comp) {
    if(vis[u] != -1) 
        return vis[u] == bi;
    vis[u] = bi;

    if(bi) {
        col[comp]++;
        co[comp].push_back(u);
    } else no[comp].push_back(u);
    total[comp]++;

    int ans = 1;
    for (int v: G[u]) 
        ans &= f(v, 1 - bi, comp);    
    return ans;
}

int main() {

    memset(vis, -1, sizeof vis);

    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    bool flag = 1;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if(vis[i] == -1) {
            flag &= f(i, 0, cur++);
        }
    }

    if(!flag) return puts("NO"), 0;

    dp[cur][b] = 1;

    for (int i = cur - 1; i >= 0; --i) {
        for (int j = 0; j <= b; ++j) {
            int bl = col[i];
            int wt = total[i] - bl;
            dp[i][j] |= dp[i + 1][j + bl];
            dp[i][j] |= dp[i + 1][j + wt];
        }
    }
    
    if(!dp[0][0]) return puts("NO"), 0;

    puts("YES");

    int current = 0;

    for (int i = 0; i < cur; ++i) {
        int bl = col[i];
        int wt = total[i] - bl;

        if(dp[i + 1][current + bl]) {
            current += bl;
            for (int x: co[i]) 
                ans[x] = 2;
            
        } else if(dp[i + 1][current + wt]) {
            current += wt;
            for (int x: no[i]) 
                ans[x] = 2;
        }
    }
    
    int p = 1;
    int cnt = 0;
    while(cnt < a and p <= n) {
        if(!ans[p]) {
            ans[p] = 1;
            cnt++;
        }
        p++;
    }


    cnt = 0;

    while(cnt < c and p <= n) {
        if(!ans[p]) {
            ans[p] = 3;
            cnt++;
        }
        p++;
    }

    for (int i = 1; i <= n; ++i)
        printf("%d", ans[i]);
    puts("");

    return 0;
}

