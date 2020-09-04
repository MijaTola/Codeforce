#include <bits/stdc++.h>

using namespace std;

int n,m;
string s;
vector<int> G[300010];
int vis[300010];
bool dfs(int u) {
    bool ans = 0;
    for (int v: G[u]) {
        if(vis[v] == 1) return 1;
        if(vis[v] == 2) continue;
        vis[v] = 1;
        ans |= dfs(v);
    }
    vis[u] = 2;
    return ans;
}

int vis2[300010][27];
int f(int u, char cur) {
    int ans = 0;
    if(vis2[u][cur] != -1) return vis2[u][cur];
    for (int v: G[u]) {
        char c = s[v - 1];
        ans = max(ans,f (v, cur) + (c == cur));
    }
    return vis2[u][cur] = ans;
}
int main(){
    memset(vis,false,sizeof vis);

    cin >> n >> m >> s;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    
    for (int i = 1; i <= n; ++i) {
        if(vis[i] != 2) {
            vis[i] = 1;
            if(dfs(i)) return  cout << "-1\n",0;
            vis[i] = 2;
        }
    }
    
    int ans = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        memset(vis2, -1, sizeof vis2);
        for (int j = 1; j <= n; ++j) {
            if(vis2[j][i - 'a'] == -1) {
                ans = max(ans,f(j,i) + (i == s[j - 1]));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

