#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int, long long> > G[5001];
long long dp[5001][5001];
int way[5001][5001];
void dfs(int u, int cur) {

    for (auto p: G[u]) {
        int v = p.first;
        long long w = p.second;
        if (dp[v][cur + 1] > dp[u][cur] + w) {
            dp[v][cur + 1] = dp[u][cur] + w;
            way[v][cur + 1] = u;
            dfs(v, cur + 1);
        }
    }
}
int main() {
    
    for (int i = 0; i < 5001; ++i)
        for (int j = 0; j < 5001; ++j)
            dp[i][j] = 2e9;
 
    int n,m,t;
    cin >> n >> m >> t;
    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
    }
    dp[1][1] = 0;
    way[1][1] = -1;
    dfs(1, 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(dp[n][i] <= t) 
            cnt = i;
    }
     
    cout << cnt << "\n";
    vector<int> ans;
        
    while(way[n][cnt] != -1) {
        int aux = n;
        n = way[aux][cnt];
        cnt--;
        ans.push_back(aux);
    }
    ans.push_back(n);
    reverse(ans.begin(), ans.end());
    for (int x: ans) cout << x << " ";
    cout << "\n";
    return 0;
}
