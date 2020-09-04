#include <bits/stdc++.h>

using namespace std;

int d[1010][1010][3];
pair<int,int> vv[3];
pair<int,int> way[1010][1010][3];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool ver(int x, int y, int c) {
    return x >= 0 and y >= 0 and x < 1010 and y < 1010 and d[x][y][c] == -1;
}
void bfs(int x,int y, int c) {
    queue<pair<int,int> > q;

    q.push(make_pair(x,y));
    d[x][y][c] = 0;
    way[x][y][c] = make_pair(x,y);
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(ver(u,v,c)) {
                d[u][v][c] = d[x][y][c] + 1;
                way[u][v][c] = make_pair(x,y);
                q.push(make_pair(u,v));
            }
        }
    }
}

int main() {
    memset(d, -1, sizeof d);
    memset(way, -1, sizeof way);
    for (int i = 0; i < 3; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        vv[i] = make_pair(x,y);
        bfs(x,y,i);
    }
    int x,y;
    int ans = 1e9;
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            int sum = d[i][j][0] + d[i][j][1] + d[i][j][2];
            if(sum < ans) {
                x = i, y = j;
                ans = sum;
            }
        }
    }
    set<pair<int,int> > a;
    for (int i = 0; i < 3; ++i) {
        int u = x;
        int v = y;
        while(u != vv[i].first or v != vv[i].second) {
            a.insert(make_pair(u,v));
            int w = way[u][v][i].first;
            int z = way[u][v][i].second;
            u = w, v = z;
        }
        a.insert(make_pair(u,v));

    }
    cout << a.size() << "\n";
    for (pair<int,int> p: a)
        printf("%d %d\n", p.first,p.second);
    return 0;
}

