#include <bits/stdc++.h>

using namespace std;

int p[200010];
int is[200010];
int dp[200010];
int ans[200010];

int n,m,k;
void init() { for (int i = 0; i < 200010; ++i) p[i] = i;}
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}
void merge(int x,int y) { p[find(y)] = find(x);}
vector<pair<int, int> > G[100010];
vector<tuple<int,int,int> > e;
vector<int> c;

bool f(int u, int pr = -1) {
    int ans = is[u];
    for (auto p: G[u]) {
        int v = p.first;
        int w = p.second;
        if(v == pr) continue;
        bool a = f(v, u);
        if(a) {
            ans = 1;
            dp[u] = max(dp[u], dp[v]);
            dp[u] = max(dp[u], w);
        }
    }
    return ans;
}

int main() {
    
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        c.push_back(x);
        is[x] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        e.push_back({w,x,y});
    }

    sort(e.begin(), e.end());
    init();
    for (auto t: e) {
        int x,y,w;
        tie(w, x, y) = t;

        if(find(x) != find(y)) {
            merge(x, y);
            G[x].push_back({y,w});
            G[y].push_back({x,w});
        }
    }

    for (int j = 1; j <= n; ++j) {
        if(is[j]) {
    f(j);
            for (int i = 0; i < k; ++i) 
                cout << dp[j] << " ";
            cout << "\n";
            return 0;
        }
    }

    return 0;
}
