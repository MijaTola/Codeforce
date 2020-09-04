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

using namespace std;

typedef long long ll;

vector<pair<int,ll> > G[100010];
int pos[100010];
bool storage[100010];
int main(){
    int n,m,k; cin >> n >> m >>k;

    for (int i = 0; i < m; ++i){
        int x,y; ll w;
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    
    ll ans = 1e10;
    memset(storage,false,sizeof storage);
    for (int i = 0; i < k; ++i){
        cin >> pos[i];
        storage[pos[i]] = true;
    }

    for (int i = 0; i < k; ++i){
        int u = pos[i];
        for (pair<int,ll> v: G[u]){
            if(!storage[v.first]){
                ans = min(ans,v.second);
            }
        }
    }
    if(ans == 1e10) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

