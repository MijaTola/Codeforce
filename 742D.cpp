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
int n,m,w;
int wt[1010];
int b[1010];
bool vis[1010];
vector<int> G[1010];
vector<int> D[1010];
int totalw[1010];
int totalb[1010];

long long dp[1010][1010];
void dfs(int u, int group){
    D[group].push_back(u);
    totalw[group] += wt[u];
    totalb[group] += b[u];
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v,group);
        }
    }
}
int c;
long long f(int x, int capacity){
    if(x == c) return 0;
    if(dp[x][capacity] != -1) return dp[x][capacity];
    long long ans = 0;
    if(totalw[x] <= capacity) ans = max(ans,f(x+1,capacity-totalw[x])+totalb[x]);
    for (int u: D[x]) if(wt[u] <= capacity) ans = max(ans,f(x+1,capacity-wt[u])+b[u]);
    ans = max(ans,f(x+1,capacity));
    return dp[x][capacity] = ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(vis,false,sizeof vis);
    memset(dp,-1,sizeof dp);
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i) cin >> wt[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    c = -1;
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            dfs(i,++c);
        }
    }
    c++;    
    cout << f(0,w) << "\n";
    return 0;
}

