#include <bits/stdc++.h>

using namespace std;

int vis[210];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof vis);
        queue<pair<int,int> > q;
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            x--;
            q.push({x, 1});
        }

        int ans = 1;
        while(!q.empty()) {
            int u = q.front().first;
            int c = q.front().second;
            q.pop();
            if(vis[u]) continue;
            ans = max(ans, c);
            vis[u] = 1;
            if(u - 1 >= 0) q.push({u - 1, c + 1});
            if(u + 1 < n) q.push({u + 1, c + 1});
        }
        cout << ans << "\n";
    }
    return 0;
}

