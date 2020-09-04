#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> G[210];
vector<int> GT[210];
vector<int> topo;
vector<int> v;
stack<int> s;
bool vis[210];
int scc[210];
int sr[210];
int n,m,sz;
void dfs(int u){
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
    s.push(u);
}
void dfs2(int u,int num){
    for (int i = 0; i < (int)GT[u].size(); ++i){
        int v = GT[u][i];
        if(scc[v] == -1){
            scc[v] = num;
            dfs2(v,num);
        }
    }
}
int no(int p){
    return (p < n) ? p + n : p - n;
}

void kosaraju(){
    memset(vis,false,sizeof vis);
    memset(scc,-1,sizeof scc);
    
    for (int i = 0; i < 2*n; ++i){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
    int color = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(scc[u] == -1){
            scc[u] = ++color;
            dfs2(u,color);
        }
        topo.push_back(u);
    }

    for (int i = 0; i < n; ++i)
        if(scc[i] == scc[i+n]){
            puts("Impossible"); return;
        }

    for (int i = 1; i <(int)topo.size(); ++i){
        sr[topo[i]] = sr[no(topo[i])]+1;
    }
}
void add(int p, int q){
    G[no(p)].push_back(q);
    GT[q].push_back(no(p));
    G[no(q)].push_back(p);
    GT[p].push_back(no(q));
}
int main(){
    
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; ++i){
        int p,q;
        scanf("%d %d",&p,&q);
        p--,q--;
        add(p,no(p));
        add(p,no(q));
        add(q,no(p));
        add(q,no(q));
        v.push_back(p);
    }
    kosaraju();
    for (int i = 0; i < m; ++i){
        if(sr[v[i]] < sr[no(v[i])] or sr[no(v[i])]) printf("i");
        else printf("o");
    }
    return 0;
}

