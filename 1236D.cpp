#include <bits/stdc++.h>

using namespace std;

vector<int> dx[100010];
vector<int> dy[100010];
bool vx[100010];
bool vy[100010];

long long n,m,k,s;
int u = 0, l = 0, d = n + 1, r = m + 1;

void dfs(int x, int y, int dir) {
    if(dir == 0 and !vx[x]) {
        int lr = lower_bound(dx[x].begin(), dx[x].end(), y) - dx[x].begin();
        r = min(dx[x][lr] - 1, r - 1);
        s += abs(r - y);
        u = x;
        vx[x] = 1;
        dfs(x, r, (dir + 1) % 4);
    }
    if(dir == 1 and !vy[y]) {
        int ld = lower_bound(dy[y].begin(), dy[y].end(), x) - dy[y].begin();
        d = min(dy[y][ld] - 1, d - 1);

        s += abs(x - d);
        r = y;
        vy[y] = 1;
        dfs(d, y, (dir + 1) % 4);
    }

    if(dir == 2 and !vx[x]) {
        int ll = lower_bound(dx[x].begin(), dx[x].end(), y) - dx[x].begin() - 1;
        l = max(dx[x][ll] + 1,l + 1);
        s += abs(y - l);
        d = x;
        vx[x] = 1;
        dfs(x, l, (dir + 1) % 4);
    }

    if(dir == 3 and !vy[y]) {
        int lu = lower_bound(dy[y].begin(), dy[y].end(), x) - dy[y].begin() - 1;
        u = max(dy[y][lu] + 1, u + 1);
        s += abs(u - x);
        l = y;
        vy[y] = 1;
        dfs(u, y, (dir + 1) % 4);
    }
}

int main() {

    cin >> n >> m >> k;
    u = 0, l = 0, d = n + 1, r = m + 1;
    for (int i = 0; i < k ;++i) {
        int x,y;
        cin >> x >> y;
        dx[x].push_back(y);
        dy[y].push_back(x);
    }
    for (int i = 1; i < 100010; ++i) {
        dx[i].push_back(m + 1);
        dx[i].push_back(0);
        sort(dx[i].begin(), dx[i].end());
    }

    for (int i = 1; i < 100010; ++i) {
        dy[i].push_back(n + 1);
        dy[i].push_back(0);
        sort(dy[i].begin(), dy[i].end());
    }

    dfs(1,1,0);
    if(s + 1== n * m - k) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

