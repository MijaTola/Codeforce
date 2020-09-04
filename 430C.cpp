#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
bool init[100010];
bool goal[100010];
vector<int> ans;
void dfs(int u, int h, bool c1, bool c2,int p){
    if(h % 2 == 0){
        if(c1) init[u] = !init[u];
        if(init[u] != goal[u]){
            init[u] = goal[u];
            ans.push_back(u);
            for (int i = 0; i < (int)G[u].size(); ++i){
                int v = G[u][i];
                if(v == p) continue;
                dfs(v,h + 1, !c1, c2, u);
            }
        }else{
            for (int i = 0; i < (int)G[u].size(); ++i){
                int v = G[u][i];
                if(v == p) continue;
                dfs(v,h + 1, c1, c2, u);
            }
        }
    }else{
        if(c2) init[u] = !init[u];
        if(init[u] != goal[u]){
            ans.push_back(u);
            for (int i = 0; i < (int)G[u].size(); ++i){
                int v= G[u][i];
                if(v == p) continue;
                dfs(v, h + 1, c1, !c2, u);
            }
        }else{
            for (int i = 0; i < (int)G[u].size(); ++i){
                int v = G[u][i];
                if(v == p) continue;
                dfs(v, h + 1, c1, c2, u);
            }
        
        }
    }
}
int main(){

    memset(init,false,sizeof init);
    memset(goal,false,sizeof goal);
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n - 1; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i){
        int x; scanf("%d",&x);
        init[i] = x;
    }
    
    for (int i = 1; i <= n; ++i){
        int x; scanf("%d",&x);
        goal[i] = x;
    }
    dfs(1,0,0,0,1);
    printf("%d\n",(int)ans.size());

    for (int i = 0; i < (int)ans.size(); ++i)
        printf("%d\n", ans[i]);

    puts("");
    return 0;
}

