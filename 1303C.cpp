#include <bits/stdc++.h>

using namespace std;

int sz;
set<int> G[30];
int vis[30];
int way[30];
bool dfs(int u, int p = -1) {
    if(vis[u]) return 1;
    vis[u] = 1;
    bool ans = 0;
    for (int v: G[u]) {
        if(v == p) continue;
        ans |= dfs(v, u);
    }
    return ans;
}

int bfs(int u) {
    memset(vis, 0, sizeof vis);

    queue<int> q;
    q.push(u);
    way[u] = u;
    int last = -1;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        last = u;
        for (int v: G[u]) {
            if(!vis[v]) {
                q.push(v);
                way[v] = u;
            }
        }
    }
    return last;
}
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        memset(vis, 0, sizeof vis);
        string s;
        cin >> s;
        sz = s.size();
        for (int i = 0; i < sz - 1; ++i) {
            G[s[i] - 'a'].insert(s[i + 1] - 'a');
            G[s[i + 1] - 'a'].insert(s[i] - 'a');
        }
        
        if(dfs(s[0] - 'a')) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int ini = bfs(s[0] - 'a');
        int last = bfs(ini);
        
        memset(vis, 0, sizeof vis);
        string ans = "";
        while(way[last] != last) {
            ans += (char)(last + 'a');
            vis[last] = 1;
            last = way[last];
        }
        ans += (char)(last + 'a');
        vis[last] = 1;


        for (int i = 0; i < 26; ++i)
            if(!vis[i]) ans += (char)(i + 'a');
        cout << ans << "\n";
    }
    return 0;
}

