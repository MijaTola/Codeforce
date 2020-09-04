#include <bits/stdc++.h>

using namespace std;

int n,k;
char m[2010][2010];
int dp[2010][2010];
int dis[4000010];
pair<int,int> way[2010][2010];
int main() {
    memset(dp, -1, sizeof dp);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
            way[i][j] = {-1, -1};
        }

    for (int i = 0; i < 4000010; ++i)
        dis[i] = 1e9;

    queue<pair<pair<int,int>, int> > q;
    dis[0] = m[0][0] - 'a';
    q.push({{0,0}, 0});

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(dis[c] < m[x][y] - 'a' or (x == n - 1 and y == n - 1)) continue;
        if(x >= n or y >= n) continue;
        int a1 = 1e9, a2 = 1e9;
        if(x + 1 < n) a1 = m[x + 1][y] - 'a';
        if(y + 1 < n) a2 = m[x][y + 1] - 'a';

        if(a1 < a2 and m[x + 1][y] - 'a' < dis[c + 1]) {
            dis[c + 1] = m[x + 1][y] - 'a';
            q.push({{x + 1, y}, c + 1});
            way[x + 1][y] = {x,y};
        } else if(a1 > a2 and m[x][y + 1] - 'a' < dis[c + 1]) {
            dis[c + 1] = m[x][y + 1] - 'a';
            q.push({{x, y + 1}, c + 1});
            way[x][y + 1] = {x,y};
        } else if(m[x][y + 1] - 'a' < dis[c + 1]) {
            dis[c + 1] = m[x][y + 1] - 'a';
            q.push({{x + 1, y}, c + 1});
            q.push({{x, y + 1}, c + 1});
            way[x][y + 1] = {x,y};
            way[x + 1][y] = {x,y};
        }
    }

    auto p = way[n - 1][n - 1];
    string s = "";
    s += m[n - 1][n - 1];
    while(p.first != -1) {
        auto x = p;
        s += m[p.first][p.second];
        p = way[x.first][x.second];
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n and k; ++i) 
        if(s[i] > 'a') s[i] = 'a', k--;
    cout << s << "\n";
    return 0;
}

