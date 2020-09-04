#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> G[100010];
bool vis[100010];
int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    priority_queue<int> q;

    q.push(-1);
    vector<int> ans;
    while(!q.empty()) {
        int u = -q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        ans.push_back(u);
        for (int v: G[u]) 
            q.push(-v);       
        
    }
    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}

