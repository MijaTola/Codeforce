#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,pair<int,int> > >e;

int parent[200010];
void init() {
    for (int i = 0; i < 200010; ++i)
        parent[i] = i;
}

int  find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x,int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        e.push_back({w,{x,y}});
    }
    unordered_set<int> s;
    init();
    sort(e.begin(),e.end());
    long long mst = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = e[i].second.first;
        int y = e[i].second.second;
        int w = e[i].first;
        if(find(x) != find(y)) {
            merge(x,y);
            mst += w;
            s.insert(w);
        } else while(s.count(w)) {
            ans++;w++;
        }
    }
    cout << ans << "\n";
    return 0;
}

