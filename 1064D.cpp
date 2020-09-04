#include <bits/stdc++.h>

using namespace std; 
char a[2010][2010];
int d[2010][2010];
bool vis[2010][2010];
int n,m,r,c,ll,rr;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int x,int y) {
    return x >= 0 and x < n and y >= 0 and y < m and a[x][y] == '.';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    memset(vis, 0, sizeof vis);
    cin >> n >> m >> r >> c >> ll >> rr;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }

    r--,c--;
    queue<pair<pair<int,int> ,pair<int,int> > > q;
    q.push(make_pair(make_pair(r,c),make_pair(ll,rr)));
    set<pair<int,int> > s;
    s.insert(make_pair(r,c));
    d[r][c] = 0;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int left = q.front().second.first;
        int right = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(!ver(u,v)) continue;
            if(i <= 1 and !vis[u][v]) {
                vis[u][v] = 1;
                s.insert(make_pair(u,v));
                q.push(make_pair(make_pair(u,v),make_pair(left,right)));
                continue;
            }
            if(i == 2) {
                if(right >= 0) {
                    s.insert(make_pair(u,v));
                    q.push(make_pair(make_pair(u,v),make_pair(left,right - 1)));
                }
                continue;
            }
            if(i == 3) {
                if(left >= 0) {
                    s.insert(make_pair(u,v));
                    q.push(make_pair(make_pair(u,v),make_pair(left - 1,right)));
                }
                continue;
            }
       }
    }
    
    cout << s.size() << "\n";
    return 0;
}

