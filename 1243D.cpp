#include <bits/stdc++.h>

using namespace std;

int out[1000100];
int p[1000100];
set<int> v[1000100], vis;

void init() {
    for (int i = 0; i < 1000100; ++i)
        p[i] = i;
}

int f(int x) {
    return x == p[x] ? x : p[x] = f(p[x]);
}

void merge(int x, int y) {
    p[f(y)] = f(x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int n,m;
    cin >> n >> m;
    
    vector<pair<int,int> > b;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
        out[x]++,out[y]++;
    }
    
    for (int i = 1; i <= n; ++i)
        vis.insert(i);
    
    for (int i = 1; i <= n; ++i) {
        if(!vis.count(i)) continue;
        queue<int> q;
        q.push(i);
        vis.erase(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto it = vis.begin(); it != vis.end();) {
                if(!v[u].count(*it)) {
                    merge(u,*it);
                    q.push(*it);
                    vis.erase(*it);
                    it = vis.upper_bound(*it);
                }else it++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += f(i) == i;

    cout << ans - 1<< "\n";
    return 0;
}

