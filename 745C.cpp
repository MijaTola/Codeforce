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

vector<int> G[1010];
vector<int> s;
int c[1010];
int sz[1010];
int e[1010];
vector< pair<int,int> > edges;

void dfs(int u, int color){
    for (int v: G[u]){
        if(c[v] == -1){
            c[v] = color;
            sz[color]++;
            dfs(v,color);
        }
    }
}
int main(){
    memset(c,-1,sizeof c);
    int n,m,k; 
    cin >> n >> m >> k;
    
    for (int i = 0; i < k; ++i){
        int x; cin >> x;
        s.push_back(x);
    }
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        edges.push_back({x,y});
    }
    int color = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        c[s[i]] = color;
        sz[color]++;
        dfs(s[i],color);
        color++;
    }
    int mx = -1;
    int t = -1;
    for (int i = 0; i < color; ++i){
        if(sz[i] > mx){
            mx = sz[i];
            t = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        if(c[i] == -1){
            c[i] = t;
            sz[t]++;
            dfs(i,t);
        }
    for (int i = 0; i < (int)edges.size(); ++i)
        e[c[edges[i].first]]++;
    
    for (int i = 0; i < color; ++i){
        int nodes = sz[i];
        int total = (nodes*(nodes-1))/2;
        total -= e[i];
        ans += total;
    }
    cout << ans << "\n";
    return 0;
}

