#include <bits/stdc++.h>

using namespace std;

vector<int> G[500010];
bool vis[500010];

bool dfs(int u, int p = -1) {
    if(vis[u]) return 0;
    vis[u] = 1;
    int ans = 1;
    for (int vv:G[u]) {
        if(vv == p) continue;
        ans &= dfs(vv, u);
    }
    return ans;
}
 
int main() {

    int n;
    cin >> n;
    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(), v.end());

    set<pair<int,int> > fin;

    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if(cur >= n) return cout << "NO\n", 0;
        while(!fin.empty() and (*fin.begin()).first < v[i].first) 
            fin.erase(fin.begin());
        if(cur >= n) return cout << "NO\n", 0;
        if(i and fin.empty()) cnt++;
        for (auto x: fin) {
            if(x.first <= v[i].second) {
                cur++;
                if(cur >= n) return cout << "NO\n", 0;
                G[x.second].push_back(i);
                G[i].push_back(x.second);
            } else break;
        }
        fin.insert({v[i].second, i} );
    }
    
    cur = 0;
    
    dfs(0);
    for (int i = 0; i < n; ++i)
        cur += vis[i];
    cout << (cur == n  and !cnt ? "YES" :"NO") << "\n";

    return 0;
}


