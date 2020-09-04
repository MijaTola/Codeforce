#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> G[500010];
set<int> S[500010];
bool vis[500010];
int t[500010];

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;

    queue<pair<int,int> > q;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        if(t[i] == 1) {
            t[i] = 0;
            q.push({-t[i], i});
        }
    }

    bool flag = 1;

    for (int i = 1; i <= n; ++i) {
        for (int v: G[i]) {
            if(t[v] == t[i])
                flag = 0;
        }
    }

    if(!flag) {
        cout << "-1\n";
        exit(0);
    }

    vector<int> ans;
    while(!q.empty()) {
        int nd = q.front().second;
        int tp = q.front().first;
        q.pop();
        if(vis[nd]) continue;

        vis[nd] = 1;
        ans.push_back(nd);

        for (int v: G[nd]) { 

            if(tp < t[v]) S[v].insert(tp);

            if((int)S[v].size() + 1 == t[v]) q.push({-t[v], v});
        }
    }

    if((int)ans.size() != n) {
        cout << "-1\n";
        exit(0);
    }

    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}

