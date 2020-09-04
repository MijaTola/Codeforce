#include <bits/stdc++.h>

using namespace std;

int n;
long long a[3][100010];
int vis[100010];
int dis[100010];
int res[100010];
vector<int> G[100010];

int bfs(int x) {
    memset(vis, -1, sizeof vis);
    queue<pair<int,int> > q;
    q.push({x,0});
    int mx = 0;
    int id = -1;
    while(!q.empty()) {
        int u = q.front().first;
        int c = q.front().second;
        q.pop();
        if(vis[u] != -1) continue;
        vis[u] = c;
        if(c > mx) {
            mx = c;
            id = u;
        }
        for (int v: G[u]) 
            q.push({v, c + 1});
    }
    return id;
}

vector<pair<int,int> > nodes;
long long dp[100010][4][4];

long long f(int pos, int l1, int l2) {
    if(pos == (int)nodes.size()) return 0;
    long long &ans = dp[pos][l1][l2];
    if(ans != -1) return ans; 
    ans = 1e17;
    for (int i = 0; i < 3; ++i) 
        if(i != l1 and i != l2)  
            ans = min(ans, f(pos + 1, l2, i) + a[i][nodes[pos].second]);
    return ans;
}

void r(int pos, int l1, int l2) {
    if(pos == (int)nodes.size()) return;
    long long ans = 1e17;
    int id = -1;
    for (int i = 0; i < 3; ++i) {
        if(i != l1 and i != l2) {
            if(f(pos + 1, l2, i) + a[i][nodes[pos].second] < ans) {
                ans = f(pos + 1, l2, i) + a[i][nodes[pos].second];
                id = i;
            }
        }
    }
    res[nodes[pos].second] = id;
    r(pos + 1, l2, id);
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[0][i];

    for (int i = 1; i <= n; ++i)
        cin >> a[1][i];

    for (int i = 1; i <= n; ++i)
        cin >> a[2][i];

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    int z = bfs(1);
    bfs(z);

    for (int i = 1; i <= n; ++i) 
        dis[vis[i]]++;
    
    for (int i = 1; i <= n; ++i) {
        if(dis[i] > 1) return cout << "-1\n",0;
        nodes.push_back({vis[i], i});
    }

    sort(nodes.begin(), nodes.end());
    
    long long ans = 1e17;
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j)
            if(i != j) ans = min(ans, f(2, i, j) + a[i][nodes[0].second] + a[j][nodes[1].second]);

    cout << ans << "\n";

    ans = 1e17;
    int id = -1;
    int id2 = -1;
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j) {
            if(i != j) if(f(2, i, j) + a[i][nodes[0].second] + a[j][nodes[1].second] < ans) {
                ans = f(2, i, j) + a[i][nodes[0].second] + a[j][nodes[1].second];
                id = i;
                id2 = j;
            }
        }

    res[nodes[0].second] = id;
    res[nodes[1].second] = id2;
    r(2,id, id2);
    for (int i = 1; i <= n; ++i)
        cout << res[i] + 1<< " ";
    cout << "\n";
    return 0;
}

