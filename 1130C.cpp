#include <bits/stdc++.h>

using namespace std;

char c[55][55];
int vis[55][55];
int n;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n 
        and vis[x][y] == -1 and c[x][y] == '0';
}
void bfs(int s,int t, int type) {
    queue<pair<int,int> >q;
    q.push({s,t});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(vis[x][y] != -1) continue;
        vis[x][y] = type;
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(ver(u,v)) q.push({u,v});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(vis, -1, sizeof vis);
    cin >> n;
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--,r2--,c2--;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];
    bfs(r1,c1,1);
    bfs(r2,c2,2);

    if(vis[r2][c2] == 1) return cout << "0\n",0;
    
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if(vis[i][j] == 1 and vis[k][l] == 2) {
                        int ii = (i + 1);
                        int jj = (j + 1);
                        int kk = (k + 1);
                        int ll = (l + 1);
                        ans = min(ans, (long long)(ii - kk) * (ii - kk) + (jj - ll) * (jj - ll));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

