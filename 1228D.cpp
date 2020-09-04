#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> G[100010];
set<int> adj[100010];
int color[100010];

int main() {
    memset(color, -1, sizeof color);
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    
  
    return 0;
}

