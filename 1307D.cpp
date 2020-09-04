#include <bits/stdc++.h>

using namespace std;

bool sp[200010];
vector<int> G[200010];
int dis[200010][2];
int way[200010];

int main() {

    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d",&x);
        sp[x] = 1;
    }
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    auto bfs= [](int u, int type) {
        memset(way, -1, sizeof way);
        queue<int> q;
        q.push(u);
        dis[u][type] = 0;
        way[u] = u;

        while(!q.empty() ) {
            u = q.front();
            q.pop();
            for (int v: G[u]) {
                if(dis[v][type] != -1) continue;
                dis[v][type] = dis[u][type] + 1;
                way[v] = u;
                q.push(v);
            }
        }
    };

    memset(dis, -1, sizeof dis);
    bfs(n, 1);
    bfs(1, 0);
    
    int pos = n;
    vector<int> b;
    while(way[pos] != pos) {
        if(sp[pos]) b.push_back(pos);
        pos = way[pos];
    }
    if(sp[pos]) b.push_back(pos);
    
    reverse(b.begin(), b.end());
    
    if(k - b.size() >= 2) return printf("%d\n", dis[n][0]), 0;
    
    int ans = dis[n][0];
    int ans2 = -1;
    for (int i = 0; i < (int)b.size() - 1; ++i) {
        int x = b[i];
        int y = b[i + 1];
        if(dis[x][0] + dis[y][1] + 1 <= dis[n][0]) 
            ans2 = max(ans2, dis[x][0] + dis[y][1] + 1);
        
    }
        
    int mx1 = 1e9;
    int mx2 = 1e9;
    int id1 = 0;
    int id2 = 0;
    
    for (int i = 1; i <= n; ++i) {
        if(!sp[i]) continue;
        if(mx1 > dis[i][0]) {
            mx1 = dis[i][0];
            id1 = i;
        }
        if(mx2 > dis[i][1]) {
            mx2 = dis[i][1];
            id2 = i;
        }
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        int x = b[i];
        int y = id2;
        if(x == y) continue;
        int curT = dis[x][0] + dis[y][1] + 1;
        if(curT < dis[n][0]) {
            ans = max(ans, curT);
        }
        x = id1;
        y = b[i];
        if(x == y) continue;
        curT = dis[x][0] + dis[y][1] + 1;
        if(curT < dis[n][0]) {
            ans = max(ans, curT);
        }
    }
    if(ans2 != -1) ans = min(ans, ans2);
    printf("%d\n", ans);

    return 0;
}

