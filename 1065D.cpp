#include <bits/stdc++.h>

using namespace std;

int n;
int v[15][15];
int dis[15][15][15][3];
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

queue<pair<pair<int,int>, pair<pair<int,int>,int> > > q;

bool ver(int x,int y) {
    return x >= 0 and x < n and y >= 0 and y < n;
}

int main() {
    for (int i = 0; i < 15; ++i) 
        for (int j = 0; j < 15; ++j)
            for (int k = 0; k < 15; ++j)
                for (int l = 0; l < 15; ++l) {
                    dis[i][j][l][k] = 1e9;
                }
    cin >> n;
    int xi,yi,xf,yf;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            if(v[i][j] == 1) xi = i, yi = j;
            if(v[i][j] == 9) xf = i, yf = j;
        }
        
    q.push({{xi,yi},{{0,0},0}});//caballo
    q.push({{xi,yi},{{1,0},0}});//alfil
    q.push({{xi,yi},{{2,0},0}});//torre
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int pi = q.front().second.first.first;
        int moves = q.front().second.first.second;
        int changes = q.front().second.second;
        q.pop(); 
        //caballo
        for (int i = 0; i < 8; ++i) {
            int u = dx[i] + x;
            int vv = dy[i] + y;
            if(!ver(u,vv)) continue;
            if(v[x][y] + 1 != v[u][vv]) continue;
            q.push({{u,vv},{{0,moves + 1 + (0 != pi)},changes + (0 != pi)}});//torre
        }

        for (int i = 1; i <= n; ++i) {
            int u = x;
            int vv = (y + i) % n;
            if(v[x][y] + 1 != v[u][vv]) continue;
            q.push({{u,vv},{{1,moves + 1 + (1 != pi)},changes + (1 != pi)}});//torre
        }

        for (int i = 1; i <= n; ++i) {
            int u,vv;
            u = (x + i) % n;
            vv = y;
            if(v[x][y] + 1 != v[u][vv]) continue;
            q.push({{u,vv},{{1,moves + 1 + (1 != pi)},changes + (1 != pi)}});//torre
        }

        int u = x;
        int vv = y;
        while(ver(u, vv)) {
            if(v[x][y] + 1 == v[u][vv])  {
                q.push({{u,vv},{{2,moves + 1 + (2 != pi)},changes + (2 != pi)}});//alfil
            }
            u--,vv++;
        }

        u = x;
        vv = y;
        
        while(ver(u, vv)) {
            if(v[x][y] + 1 == v[u][vv]) {
                q.push({{u,vv},{{2,moves + 1 + (2 != pi)},changes + (2 != pi)}});//alfil
            }
            u++,vv--;
        }
        u = x;
        vv = y;
        while(ver(u, vv)) {
            if(v[x][y] + 1 == v[u][vv])  {
                q.push({{u,vv},{{2,moves + 1 + (2 != pi)},changes + (2 != pi)}});//alfil
            }
            u--,vv--;
        }

        u = x;
        vv = y;
        
        while(ver(u, vv)) {
            if(v[x][y] + 1 == v[u][vv]) {
                q.push({{u,vv},{{2,moves + 1 + (2 != pi)},changes + (2 != pi)}});//alfil
            }
            u++,vv++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
        cout << "\n";
    }
    return 0;
}

