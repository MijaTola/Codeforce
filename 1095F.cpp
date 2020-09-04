#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
long long v[200010],w;
int parent[200010];
vector<pair<long long,pair<int,int> > > e;

void init() {
    for (int i = 0; i < 200010; ++i)
        parent[i] = i;
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    parent[py] = px;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    long long mn = LLONG_MAX;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", v + i);
        if(v[i] < mn) {
            mn = v[i];
            id = i;
        } 
    }
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &x, &y, &w);
        x--,y--;
        e.push_back(make_pair(w, make_pair(x,y)));
    }

    for (int i = 0; i < n; ++i) {
        if(i == id) continue;
        e.push_back(make_pair(v[id] + v[i], make_pair(id,i)));
    }

    sort(e.begin(), e.end());
    init();
    long long ans = 0;
    for (int i = 0; i < (int)e.size(); ++i) {
        long long w = e[i].first;
        int x = e[i].second.first;
        int y = e[i].second.second;
        if(find(x) != find(y)) {
            ans += w;
            merge(x,y);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

