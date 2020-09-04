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

vector<int> G[150100];
set<pair<int,int> > edges;
bool vis[150100];
int e;
int dfs(int u){
    int ans = 0;
    for (int v: G[u]){
        if(!edges.count({max(u,v),min(u,v)})){
            e++;
            edges.insert({max(u,v),min(u,v)});
        }
        if(!vis[v]){
            vis[v] = true;
            ans += dfs(v)+1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; 
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bool ans = true;
    for (int i = 1; i <= n; ++i){
        e = 0;
        long long nodes = 0;
        if(!vis[i]){
            vis[i] = true;
            nodes = dfs(i)+1;
        }
        long long x = nodes*(nodes-1)/2;
        ans &= (x == e);
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

