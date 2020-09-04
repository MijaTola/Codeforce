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

typedef long long ll;

vector<int> G[200010];
int c[200010];
bool vis[200010];
set<int> s;
int dfs(int u,int color){
    int sz = 0;
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            if(color == c[v]) sz += dfs(v,color);
            else sz += min(dfs(v,color)+1,dfs(v,c[v])+2);
        }
    }
    return sz;
}
int main(){
    memset(vis,false,sizeof vis);
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 1; i <= k; ++i) cin >> c[i];
    

    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){vis[i] = true; ans += dfs(i,c[i]);}
    }
    cout <<ans << endl;
    return 0;
}

