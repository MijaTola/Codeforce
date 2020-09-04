#include <bits/stdc++.h>

using namespace std;

int n;
int parent[150100];
int sz[150100];
vector<int> v[150100];

void init() {
    for (int i = 0; i < 150100; ++i)
        parent[i] = i;
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x,int y) {
    int px = find(x);
    int py = find(y);
    if(sz[px] < sz[py]) swap(px, py);
    sz[px] += sz[py];
    for (int u: v[py]) 
        v[px].push_back(u);
    parent[py] = px;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        v[i].push_back(i);
        sz[i] = 1;
    }
    int last = 0;
    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin >> x >> y;
        if(find(x) == find(y)) continue;
        merge(x,y);
        last = x;
    }
    
    for (int x: v[find(last)])
        cout << x << " ";
    cout << "\n";
    return 0;
}
