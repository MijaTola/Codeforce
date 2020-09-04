#include <bits/stdc++.h>

using namespace std;

int n,k;
long long ans;
vector<int> G[200010];
int sub[200010];
int parent[200010];
int in[200010];
int is[200010];
int depth[200010];
vector<int> a;

void dfs(int u, int p = 0, int d = 1) {
    sub[u] = 1;
    parent[u] = p;
    depth[u] = d;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, u, d + 1);
        sub[u] += sub[v];
    }
    a.push_back(d - sub[u]);
}

int main() {

    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1);
    
   
    sort(a.begin(), a.end());

    ans = 0;

    for (int i = 0; i < k; ++i)
        ans += a[i];
    sort(a.rbegin(), a.rend());

    ans = 0;

    for (int i = 0; i < k; ++i)
        ans += a[i];

    cout << ans << "\n";
    return 0;
}
