#include <bits/stdc++.h> 

using namespace std;

vector<int> G[5010];
vector<int> G2[5010];
vector<int> GC[5010];

int scc[5010];
bool vis[5010];
stack<int> s;
int n;
void dfs(int u){
    for (int x: G[u]){
        if(!vis[x]){
            vis[x] = true;
            dfs(x);
        }
    }
    s.push(u);
}
void dfs2(int u,int num){
    for (int x: GC[u]){
        if(scc[x] == -1){
            scc[x] = num;
            dfs2(x,num);
        }
    }
}

void dfs3(int u) {
    for (int x: G2[u]) {
        if(!vis[x]) {
            vis[x] = 1;
            dfs3(x);
        }
    }
}
int kosaraju(){
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
set<pair<int,int> > edges;
int main(){
    int m;
    memset(vis,false,sizeof vis);
    memset(scc,-1,sizeof scc);
    int s;
    cin >> n >> m >> s;; 
    for (int i = 0; i < m; ++i){
        int x,y; 
        cin >> x >> y;
        G[x].push_back(y);
        GC[y].push_back(x);
    }
    
    int ans = kosaraju();

    s = scc[s];
    for (int i = 1; i <= n; ++i) {
        for (int j: G[i]) {
            if(edges.count({max(scc[i],scc[j]),min(scc[i],scc[j])})) continue;
            edges.insert({max(scc[i],scc[j]),min(scc[i],scc[j])});
            G2[scc[i]].push_back(scc[j]);
        }
    }
    memset(vis,false,sizeof vis);
    dfs3(s);
    vis[s] = 1;
    int c = 1;

    for (int i = 1; i <= ans; ++i) {
        if(!vis[i]) {
            vis[i] = 1;
            c++;
            dfs3(i);
        }
    }
    cout << c - 1 << "\n";
    return 0;
}

