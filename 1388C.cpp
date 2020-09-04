#include <bits/stdc++.h>

using namespace std;

int n,m;
int p[100010];
int h[100010];
int sz[100010];
vector<int> G[100010];
int g[100010];
int b[100010];
int total[100010];

bool dfs(int u, int pt = 0) {

    int go = 0, ba = 0;
    for (int v: G[u]) {
        if(v == pt) continue;   
        dfs(v, u);
        go = g[v];
        ba = b[v];
        sz[u] += sz[v];
    }

    sz[u] += p[u];

    int curb = 1e9;
    int ans = 1;

    if(h[u] >= 0) {
        int q = h[u];
        int w = 0;
        int df = sz[u] - abs(h[u]);
        if (df & 1) {
            return 0;
        } else {
            q += df / 2;
            w += df / 2;
        }
        curb = w;
    } else {
        int q = 0;
        int w = h[u];
        int df = sz[u] - abs(h[u]);
        if (df & 1) {
            return 0;
        } else {
            q += df / 2;
            w += df / 2;
        }
        curb = w;
    }
    
    if(abs(curb) <= go) {
        go = sz[u] - abs(curb);
        ba = abs(curb);;
    } else return 0;

    return ans;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; ++i) {
            p[i] = 0, h[i] = 0;
            G[i].clear();
        }
        for (int i = 1; i <= n; ++i) 
            cin >> p[i];

        for (int i = 1; i <= n; ++i)
            cin >> h[i];

        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        if(dfs(1)) cout << "YES\n";
        else cout << "NO\n";



    }
    return 0;
}

