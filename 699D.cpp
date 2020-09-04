#include <bits/stdc++.h>

using namespace std;

int n;
int c[200010];
bool vis[200010];
bool vi[200010];

vector<int> G[200010];
vector<int> G2[200010];
vector<int> r;
void dfs(int u, int num){
    for (int i = 0; i < (int)G2[u].size(); ++i){
        int v = G2[u][i];
        if(c[v] == -1){
            c[v] = num;
            dfs(v,num);
        }
    }
}

bool dfs2(int u){
    bool a = false;
    int cur = 0;
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        if(!vis[v]){
            vis[v] = 1;
            cur++;
            a |= dfs2(v);
        }else{
            r.push_back(v);
            return 1;
        }
    }
    if(!cur and !a) r.push_back(u);
    return a;
}
int main(){
    
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i){    
        int x; scanf("%d",&x);
        G[i].push_back(x);
        G2[i].push_back(x);
        G2[x].push_back(i);
    }
    
    memset(c,-1,sizeof c);
    int num = 1;
    for (int i = 1; i <= n; ++i){
        if(c[i] == -1){
            c[i] = num;
            dfs(i,num);
            num++;
        }
    }
    for (int i = 0; i < 200010; ++i){
        vis[i] = vi[i] = false;
    }
    for (int i = 1; i <= n; ++i){
        if(!vi[c[i]]){
            dfs2(i);
            vi[c[i]] = 1;
        }
    }
    
    int id = -1;
    for (int i = 0; i < (int)r.size(); ++i){
        if(G[r[i]].back() == r[i]){
            id = r[i];
            break;
        }
    }
    int a = 0;
    if(id == -1){
        a = 1;
        G[r[0]].push_back(r[0]);
        id = r[0];
    }
    for (int i = 0; i < (int)r.size(); ++i){
        if(G[r[i]].back() != id) G[r[i]].push_back(id);
    }

    printf("%d\n",(int)r.size() - 1 + a);
    for (int i = 1; i <= n; ++i)
        printf("%d ",G[i].back());
    puts("");
    return 0;
}
