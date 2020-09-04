#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9+7;
int n,m;
int v[100010];
bool vis[100010];
int scc[100010];
vector<int> G[100010];
vector<int> GT[100010];
stack<int> s;
void dfs(int u){
    for (int i = 0; i < (int)G[u].size(); ++i){
        int dv = G[u][i];
        if(!vis[dv]){
            vis[dv] = true;
            dfs(dv);
        }
    }
    s.push(u);
}

void dfs2(int u, int color){
    for (int i = 0; i < (int)GT[u].size(); ++i){
        int dv = GT[u][i];
        if(scc[dv] == -1){
            scc[dv] = color;
            dfs2(dv,color);
        }
    }
}

int kosaraju(){
    memset(vis,false,sizeof vis);
    memset(scc,-1,sizeof scc);
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
    int color = 0;
    while(!s.empty()){
        int u = s.top(); s.pop();
        if(scc[u] == -1){
            scc[u] = ++color;
            dfs2(u,color);
        }
    }
    return color;
}

int mn[100010];
int way[100010];
int main(){
    
    for (int i = 0; i < 100010; ++i){
        mn[i] = 1e9+7;
        way[i] = 0;
    }
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i)
        scanf("%d",v + i);

    scanf("%d",&m);

    for (int i = 0; i < m; ++i){
        int x,y; scanf("%d %d",&x,&y);
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    int c = kosaraju();

    for (int i = 1; i <= n; ++i)
        mn[scc[i]] = min(v[i],mn[scc[i]]);
    
    for (int i = 1; i <= n; ++i)
        if(mn[scc[i]] == v[i]) way[scc[i]]++;
    
    long long ans = 1;
    long long ans2 = 0;
    for (int i = 1; i <= c; ++i){
        ans = (ans * way[i]) % mod;
        ans2 += mn[i];
    }
    printf("%lld %lld\n",ans2,ans);
    return 0;
}

