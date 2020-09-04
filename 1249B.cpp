#include <bits/stdc++.h>

using namespace std;

int p[200010];
int c[200010];
int vis[200010];

void dfs(int u, int col) {
    if(vis[u] != -1) return;
    vis[u] = col;
    c[col]++;
    dfs(p[u], col);   
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            vis[i] = -1;
            c[i] = 0;
        }
        
        int cur = 0;

        for (int i = 1; i <= n; ++i) {
            if(vis[i] != -1) continue;
            cur++;
            dfs(i, cur);
        }

        for (int i = 1; i <= n; ++i) 
            cout << c[vis[i]]  << " ";
        cout << "\n";
    }
    return 0;
}

