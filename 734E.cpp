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

int n;
bool color[200010];
bool vis[200010];
int c[200010];
vector<int> G[200010];
vector<int> G2[200010];
set<pair<int,int> > edge;
pair<int,int> bfs(int x){
    queue<pair<int,pair<int,int> > > q;
    q.push({x,{0,x}});
    int mx = -1;
    int id = -1;
    while(!q.empty()){
        int u = q.front().first;
        int c = q.front().second.first;
        int parent = q.front().second.second;
        q.pop();
        if(c > mx){
            mx = c; id = u;
        }
        for(int v: G2[u])
            if(v != parent){
                q.push({v,{c+1,u}});
            }
    }
    return {id,mx};
}

void dfs(int u, int col){
    for (int v: G[u]){
        if(color[v] == color[u] and !vis[v]){
            c[v] = col;
            vis[v] = true;
            dfs(v,col);
        }
    }
}

int main(){
    memset(vis,false,sizeof vis);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 0; i < n-1; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    int col = 0;
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            c[i] = ++col;
            dfs(i,col);
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j: G[i]){
            if(c[i] != c[j] and !edge.count({max(i,j),min(i,j)})){
                edge.insert({max(i,j),min(i,j)});
                G2[c[i]].push_back(c[j]);
                G2[c[j]].push_back(c[i]);
            }
        }
    }
    int node = bfs(1).first;
    int d = bfs(node).second;
    cout << (d+1)/2<< endl;
    
    return 0;
}

