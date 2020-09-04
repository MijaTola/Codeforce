#include <bits/stdc++.h>

using namespace std;

int vis[100010];
int in[100010];
int lf[100010];
vector<int> G[100010];
int mx;

int main() {

    int n;
    cin >> n;


    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        in[x]++, in[y]++;
    }
    mx = n - 1;
    auto bfs = [&] (int u) -> pair<int,int> {
        memset(vis, -1, sizeof vis);

        queue<int> q;
        q.push(u);
        vis[u] = 0;

        int id = u, mx = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(vis[u] > mx) {
                mx = vis[u];
                id = u;
            }

            for (int v: G[u]) {
                if(vis[v] == -1) {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
        return {id, mx};
    };

    auto p = bfs(1);
    p = bfs(p.first);
    
    for (int i = 1; i <= n; ++i) {
        if(in[i] == 1) {
            int nd = G[i][0];
            lf[nd]++;
        }
    }

    for (int i = 1; i <= n; ++i) 
        if(lf[i] > 1) mx -= lf[i] - 1;
    
    if(p.second & 1) cout << 3 << " ";
    else {

        bool flag = 1;
        for (int i = 1; i <= n; ++i) {
            if(in[i] == 1) {
                flag &= vis[i] % 2 == 0;
            }
        }

        if (flag) cout << 1 << " ";
        else cout << "3 ";
    }

    cout << mx << "\n";
    
    return 0;
}

