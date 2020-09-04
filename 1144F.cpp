#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> G[200010];
int color[200010];
vector<pair<int,int> > v;
int main() {
    memset(color, -1, sizeof color);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        v.push_back({x,y});
    }

    queue<int> q;
    q.push(1);
    color[1] = 0;
    bool is = 1;
    while(!q.empty() and is) {
        int u = q.front();
        q.pop();
        for (int v: G[u]) {
            if(color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if(color[v] == color[u]) {
                is = 0;
                break;
            }
        }
    }

    if(!is) return cout << "NO\n",0;
    cout << "YES\n";
    for (auto x: v) {
        if(color[x.first] == 0) cout << 1;
        else cout << 0;
    }
    cout << "\n";
    return 0;
}
