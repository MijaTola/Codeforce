#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,int> > e;
vector<int> G[200010];
int de[200010];
int parent[200010];

void init() {
    for (int i = 0; i < 200010; ++i)
        parent[i] = i;
}

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[py] = px;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        de[x]++, de[y]++;
        e.push_back(make_pair(x,y));
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    int mx = 0, id = -1;

    for (int i = 1; i <= n; ++i)
        if(de[i] > mx) {
            mx = de[i];
            id = i;
        }
    init();
    for (int i = 0; i < (int)G[id].size(); ++i) {
        cout << id << " " << G[id][i] << "\n";
        merge(G[id][i], id);
    }


    for (int i = 0; i < (int)e.size(); ++i) {
        if(find(e[i].first) == find(e[i].second)) continue;
        merge(e[i].first, e[i].second);
        cout << e[i].first << " " << e[i].second << "\n";
    }
    return 0;
}

