#include <bits/stdc++.h>

using namespace std;

int n; 
bool vis[1010][1010];

int dx[] = {1,-1,0,0,1,-1,-1,1};
int dy[] = {0,0,-1,1,1,-1,1,-1};

bool ver(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n;
}
int main() {

    memset(vis, 0, sizeof vis);
    cin >> n;

    int ax,ay; cin >> ax >> ay;
    int bx,by; cin >> bx >> by;
    int cx,cy; cin >> cx >> cy;
    
    ax--,ay--,bx--,by--,cx--,cy--;
    for (int i = 0; i < 8; ++i) {
        int x = ax;
        int y = ay;
        vis[x][y] = 1;
        while(ver(dx[i] + x, dy[i] + y)) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            vis[u][v] = 1;
            x = u;
            y = v;
        }
    }
    
   
    queue<pair<int,int> > q;
    q.push({bx,by});
    vis[bx][by] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int u = dx[i] + x;
            int v = dy[i] + y;
            if(ver(u,v) and !vis[u][v]) {
                vis[u][v] = 1;
                q.push({u,v});
            }
        }
    }
    if(vis[cx][cy]) puts("YES");
    else puts("NO");
    return 0;
}

