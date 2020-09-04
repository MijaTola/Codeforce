#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

queue<pair<int, pair<int,int> > > q[10];
queue<pair<int,int> > q2;

char c[1010][1010];
bool vis[1010][1010];
int ans[10], s[10];
int n,m,p;


bool ver(int x,int y) {
    return x >= 0 and x < n and y >= 0 and y < m and c[x][y] == '.';
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> p;

    for (int i = 1; i <= p; ++i) 
        cin >> s[i];
    
    int able = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            c[i][j] = x;
            if(x != '#' and x != '.') {
                int p = x - '0';
                able--;
                ans[p] = 1;
                q[p].push({0,{i,j}});
                q2.push({i,j});
            }
        }
    }


    while(!q2.empty()) {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        able++;
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(ver(u,v) and !vis[u][v]) 
                q2.push({u,v});
        }

    }
    int turn = 1;
    while(able) {
        int total = 0;
        if(!q[turn].empty()) total = -q[turn].front().first;
        while(!q[turn].empty()) {
            int x = q[turn].front().second.first;
            int y = q[turn].front().second.second;
            int cc = -q[turn].front().first;
            if(cc == s[turn] + total) break;
            q[turn].pop();

            for (int i = 0; i < 4; ++i) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(ver(u,v)) {
                    able--;
                    q[turn].push({-(cc + 1), {u,v}});
                    c[u][v] = (char)(turn + '0');
                }
            }
        }
        turn++;
        if(turn > p) turn = 1;
    }
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            ans[c[i][j] - '0']++;
    
    for (int i = 1; i <= p; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}

