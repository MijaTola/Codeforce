#include <bits/stdc++.h>

using namespace std;

int n,t;
string s;
vector<int> G[200010];
bool vis[200010];
int in[200010];
int ans = 0;
queue<int> q;

bool dfs(int u, int p = -1, int d = 0) {

    int cur = 0;
    if(d > 2 and p != u) {
        ans++;
        d = 0;
        cur = 1;
        in[G[u][0]]--;
        if(in[G[u][0]]) q.push(u);
        return 1;
    }

    for (int v: G[u]) {
        if(v != p) {
            cur |= dfs(v, u, d + 1);
        }
    }
    return vis[u] = cur;
}

int main() {

    cin >> t;

    while(t--) {
        cin >> n >> s;
        
        while(!q.empty()) q.pop();

        for (int i = 0; i < n; ++i) {
            G[i].clear();
            vis[i] = 0;
            in[i] = 0;
        }

        ans = 0;

        for (int i = 0; i < n; ++i) {
            int l = (i - 1 + n) % n;
            int r = (i + 1) % n;
            if(s[i] == 'L') G[i].push_back(l), in[l]++;
            else G[i].push_back(r), in[r]++;
        }

        for (int i = 0; i < n; ++i) {
            if(in[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            dfs(q.front());
            q.pop();
        }

        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i);
            }

            while(!q.empty()) {
                dfs(q.front());
                q.pop();
            }
        }


        cout << ans << "\n";
    }
    return 0;
}

