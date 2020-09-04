#include <bits/stdc++.h>

using namespace std;

char c[55][55];
bool vis[55][55];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {

    int t;
    cin >> t;

    while(t--) {

        for (int i = 0; i < 55; ++i)
            for (int j = 0; j < 55; ++j)
                vis[i][j] = 0;
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];
        
        auto ver = [&] (int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                if(c[i][j] == 'B') {
                    for (int k = 0; k < 4; ++k) {
                        int u = i + dx[k];
                        int v = j + dy[k];
                        if(!ver(u,v) or c[u][v] != '.') continue;
                        c[u][v] = '#';
                    }
                }
            }
        }

        queue<pair<int,int> > q;

        if(c[n - 1][m - 1] == '.') 
            q.push({n - 1, m - 1});

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = 1;

            for (int i = 0; i < 4; ++i) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(ver(u,v) and c[u][v] != '#')
                    q.push({u,v});
            }

        }
        
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(c[i][j] == 'G') flag &= vis[i][j];
                if(c[i][j] == 'B') flag &= !vis[i][j];
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

