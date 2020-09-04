#include <bits/stdc++.h>

using namespace std;

int n,m, lim;
vector<int> G[200010], G2[200010], h[200010];
int vis[200010];
int col[200010];

int depth[200010];

void f(int u, int p, vector<int> ans = {}) {
    if(vis[u]) {
        int up = depth[u];
        int down = depth[p];
        if(down - up >= lim) {
            vector<int> a;
            a.push_back(ans.back());
            ans.pop_back();
            while(ans.back() != u) {
                a.push_back(ans.back());
                ans.pop_back();
            }
            cout << "2\n" << a.size() << "\n";
            for (int x: a) 
                cout << x << " ";
            cout << "\n";
            exit(0);
        }
        return;
    }
    vis[u] = 1;
    depth[u] = depth[p] + 1;
    for (int v: G[u]) {
        if(v == p) continue;
        col[v] = 1 - col[u];
        ans.push_back(v);
        f(v, u, ans);
        ans.pop_back();
    }
}

int main() {


    cin >> n >> m;
    lim = sqrt(n);
    if(lim * lim < n) lim++;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    f(1, 1, {1});

    cout << "1\n";

    for (int i = 1; i <= n; ++i) 
        h[depth[i]].push_back(i);

    memset(vis, -1, sizeof vis);

    vis[1] = 1;

    vector<int> a,b;
    for (int i = 1; i <= n; ++i)
        if(!col[i]) a.push_back(i);
        else b.push_back(i);

    int cnt = 0;
    if((int)a.size() >= lim) {
        for (auto x: a) {
            cout << x << " ";
            cnt++;
            if(cnt == lim) break;
        }
        cout << "\n";
    } else {

        for (auto x: b) {
            cout << x << " ";
            cnt++;
            if(cnt == lim) break;
        }
        cout << "\n";
    }

    return 0;
}

