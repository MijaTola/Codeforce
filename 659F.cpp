#include <bits/stdc++.h>

using namespace std;

int n,m;
long long k;
int c[1010][1010];
int val[1010][1010];
bool vis[1010][1010];
int p[1000100];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
set<int> s;

void init() {
    for (int i = 0; i < 1000100; ++i)
        p[i] = i;
}

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    p[py] = px;
    s.erase(px);
    s.erase(py);
    s.insert(px);
}

void dfs(int x, int y, int cur) {
    
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if(u >= 0 and v >= 0 and u < n and u < m and c[u][v] >= cur) {
        }
    }
}
int main() {
    
    cin >> n >> m >> k;


    vector<pair<int, pair<int,int> > > v;
    int cnt = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            v.push_back({c[i][j], {i, j}});
            val[i][j] = cnt++;
        }

    init();
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < (int)v.size(); ++i) {
        long long cur = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if(vis[x][y]) continue;
    }

    cout << "NO\n";
    
    return 0;
}

