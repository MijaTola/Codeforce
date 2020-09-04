#include <bits/stdc++.h>

using namespace std;

int c[33][33];
int dis[33][33];
int cnt[33][3];

int main() {
    int t;
    cin >> t;

    while(t--) {
        memset(dis, -1, sizeof dis);
        memset(cnt, 0, sizeof cnt);

        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];


        queue<tuple<int,int,int> > q;

        q.push({0,0,0});
        q.push({n - 1,m - 1,1});
        dis[0][0] = 1;
        dis[n - 1][m - 1] = 1;

        auto ver = [&] (int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m and dis[x][y] == -1;
        };

        int mx = 0;
        while(!q.empty()) {
            int x,y,k;
            tie(x,y,k) = q.front();
            q.pop();
            int d = dis[x][y];
            mx = max(d, mx);

            if(k == 0) {
                if(ver(x, y + 1)) {
                    q.push({x,y + 1,k});
                    dis[x][y + 1] = dis[x][y] + 1;
                }

                if(ver(x + 1, y)) {
                    q.push({x + 1,y,k});
                    dis[x + 1][y] = dis[x][y] + 1;
                }
            } else {
                if(ver(x, y - 1)) {
                    q.push({x,y - 1,k});
                    dis[x][y - 1] = dis[x][y] + 1;
                }

                if(ver(x - 1, y)) {
                    q.push({x - 1,y,k});
                    dis[x - 1][y] = dis[x][y] + 1;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt[dis[i][j]][c[i][j]]++;

            }
        }

        int ans = 0;
        for (int i = 1; i <= mx; ++i) {
            if(i == mx and (n + m - 1) & 1) continue;
            ans += min(cnt[i][0], cnt[i][1]);
        }
        cout << ans << "\n";

    }
    return 0;
}

