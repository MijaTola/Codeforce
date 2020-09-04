#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
int vis[200010];

int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        vector<int> ans, ans2;
        scanf("%d %d", &n, &m);

        for (int i = 0; i <= n; ++i) {
            G[i].clear();
            vis[i] = -1;
        }

        for (int i = 0; i < m; ++i) {
            int x,y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        vis[1] = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(vis[u] == 1) ans.push_back(u);
            if(vis[u] == 0) ans2.push_back(u);
            for (int v: G[u]) {
                if(vis[v] == -1) {
                    vis[v] = 1 - vis[u];
                    q.push(v);
                }
            }
        }
    
        if(ans2.size() < ans.size()) ans = ans2;
        printf("%d\n", (int)ans.size());

        for (int i = 0; i < (int)ans.size(); ++i)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}

