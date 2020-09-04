#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
vector<int> topo;
bool vis[200010];
int pos[200010];


void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u]) {
        dfs(v);
    }
    topo.push_back(u);
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            vis[i] = 0;
            pos[i] = 0;
        }
        topo.clear();
        vector<pair<int,int> > ans;

        for (int i = 0; i < m; ++i) {
            int x,y,c;
            cin >> c >> x >> y;
            if(c == 1) G[x].push_back(y);
            ans.emplace_back(x,y);
        }
        
        for (int i = 1; i <= n; ++i) {
            if(!vis[i]) dfs(i);
        }

        reverse(topo.begin(), topo.end());

        for (int i = 0; i < (int)topo.size(); ++i) {
            pos[topo[i]] = i;
        }
        

        bool flag = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j: G[i]) {
                flag &= pos[i] < pos[j];
            }
        }

        if(!flag) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto p: ans) {
            if(pos[p.first] < pos[p.second]) {
                cout << p.first << " " << p.second << "\n";
            } else 
                cout << p.second << " " << p.first << "\n";
        }
    }

    return 0;
}

