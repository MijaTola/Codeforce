#include <bits/stdc++.h>

using namespace std;

vector<int> G[510];
set<pair<int,int> > s;
bool vis[510];
void dfs(int u) {
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) {
            s.insert(make_pair(u,v));
            continue;
        }
        vis[v] = 1;
        dfs(v);
    }
}

bool f(int u, int x,int y) {
    bool ans = 1;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) {
            if(u == x and y == v) continue;
            return 0;
        }
        vis[v] = 1;
        ans &= f(v,x,y);
    }
    return ans;
}
int main(){
    memset(vis,false, sizeof vis);
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x,&y);
        G[x].push_back(y);
    }
    
    for (int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    

    for (pair<int,int> x: s) {
        bool ans = 1;
        memset(vis,false, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                ans &= f(i,x.first,x.second);
            }
        }
        cout << x.first << " " << x.second << " asdf;l\n";
        if(ans) return puts("YES"),0;
    }

    puts("NO");
    return 0;
}

