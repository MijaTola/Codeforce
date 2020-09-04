#include <bits/stdc++.h>

using namespace std;

map<char,int> dir;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;
char c[1010][1010];
int dis[1010][1010];
bool ver(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and c[x][y] != '*';
}


int main() {
    dir['^'] = 0;
    dir['>'] = 1;
    dir['v'] = 2;
    dir['<'] = 3;
    dir['U'] = 0;
    dir['R'] = 1;
    dir['D'] = 2;
    dir['L'] = 3;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            dis[i][j] = 1e9;
        }
    
    int ix, iy, fx, fy;
    cin >> ix >> iy >> fx >> fy;
    priority_queue<pair<int, pair<int,int> > > q;
    dis[ix][iy] = 0;
    q.push({0, {ix,iy}});

    while(!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(c[x][y] == '-' or c[x][y] == '|') {
        } else {
            int way = dir[c[x][y]];
            for (int i = 0; i < 4; ++i) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(ver(u,v)) {
                }
            }
        }
    }
    return 0;
}

