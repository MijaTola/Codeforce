#include <bits/stdc++.h>
 
using namespace std;
 
int n,m;
vector<int> G[110],a;
int dis[110][110], v[1000100], dp[1000010];

void bfs(int x) {
    queue<pair<int,int> > q;
    q.push({x,0});
    while(!q.empty()) {
        int u = q.front().first;
        int c = q.front().second;
        q.pop();
        if(dis[x][u] != -1) continue;
        dis[x][u] = c;
        for (int v: G[u]) {
            q.push({v, c + 1});
        }
    }
}

int f(int pos) {
    if(pos == m - 1) return 0;
    int &ans = dp[pos];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = pos + 1; i < min(pos + 100, m); ++i) {
        if(dis[v[pos]][v[i]] == i - pos) {
            ans = min(ans, f(i) + 1);
        }
    }
    return ans;
}

void r(int pos) {
    if(pos == m - 1) return;
    int ans = 1e9;
    int id = -1;
    for (int i = pos + 1; i < min(pos + 100, m); ++i) {
        if(dis[v[pos]][v[i]] == i - pos) {
            if(f(i) + 1 < ans) {
                ans = f(i) + 1;
                id = i;
            }
        }
    }
    a.push_back(v[id] + 1);
    r(id);
}

int main() {
    memset(dis, -1, sizeof dis);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char x;
            cin >> x;
            if(x == '1') G[i].push_back(j);
        }
    }
 
 
    for (int i = 0; i < n; ++i)
        bfs(i);
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
        v[i]--;
    }
 
    cout << f(0) + 1<< "\n";
    a.push_back(v[0] + 1);
    r(0);
    for (int x: a)
        cout << x << " ";
    cout << "\n";
    return 0;
}
