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

int n,m,t;
vector<pair<int,int> > G[5010];
pair<int,long long> dp[5010];

pair<int,long long> f(int u){
    if(u == n) return {0,0};
    int tm = -1;
    int nd = -1;
    if(dp[u].first != -1) return dp[u];
    for (pair<int,long long> v: G[u]){
        pair<int,long long> r = f(v.first);
        long long time = r.second + v.second;
        int nodes = r.first + 1;
        if(time <= t and (nodes > nd or (nodes >= nd and time < tm))){
            nd = nodes;
            tm = time;
        }
    }
    return dp[u] = {nd,tm};
}

void r(int u){
    if(u == n) return;
    int nd = -1;
    int id = 0;
    for (pair<int,long long> v: G[u]){
        pair<int,long long> r = f(v.first);
        long long time = r.second + v.second;
        int nodes = r.first + 1;
        if(time <= t and nodes > nd){
            nd = nodes;
            id = v.first;
        }
    }
    cout << id << " ";
    r(id);
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> m >> t;
    for (int i = 0; i < m; ++i){
        int x,y,w; cin >> x >> y >> w;
        G[x].push_back({y,w});
    }
    cout << f(1).first+1 << "\n";
    cout << 1 << " ";
    r(1);
    return 0;
}

