#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
int vis[200010];
int mx = 1;

int main() {
    
    int n, k;

    cin >> n >> k;
    
    int ini = 2;

    queue<int> q;

    vector<pair<int,int> > ans;
    
    for (int i = 0; i < k; ++i) {
        G[1].push_back(ini);
        G[ini].push_back(1);
        q.push(ini);
        ans.emplace_back(1, ini++);
        n--;
    }
    auto bfs = [] (int ini) {
        memset(vis, 0, sizeof vis);
        queue<pair<int,int> > q;
        q.push({ini, 0});
        int maxi = 0;
        int id = -1;
        while(!q.empty()) {
            int u = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[u] = 1;
            if(c > maxi) {
                 maxi = c;
                 id = u;
            }
            for (int v: G[u]) {
                if(!vis[v]) q.push({v, c + 1});
            }
        }
        mx = maxi;
        return id;
    };

    n--;
    while(1) {
        for (int i = 0; i < k and n; ++i, n--) {
            int u = q.front();
            q.pop();
            G[u].push_back(ini);
            G[ini].push_back(u);
            q.push(ini);
            ans.emplace_back(u, ini++);
        }
        if(!n) break;
    }
    
    int a = bfs(1);
    bfs(a);
    cout << mx << "\n";
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";

    return 0;
}

