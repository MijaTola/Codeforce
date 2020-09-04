#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int t,n,m,x,y,cur;
vector<int> G[300010];
int color[300010];

long long bipartite(int s) {
    queue<int> q;
    q.push(s);
    color[s] = 0;
    int b = 1;
    int w = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(color[u]) b = (2 * b) % mod;
        else w = (2 * w) % mod;
        for (int j = 0; j < (int) G[u].size(); ++j) {
            int v = G[u][j];
            if(color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if(color[v] == color[u]) return 0;
        }
    }
    return (w + b) % mod;
}


int main() {

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
            color[i] = -1;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
    
        bool flag = 1;
        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            if(color[i] != -1) continue;
            ans = (ans * bipartite(i)) % mod;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
