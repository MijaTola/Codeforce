#include <bits/stdc++.h>

using namespace std;

int n,m,c;
int parent[500010];
int cnt[500010];
int k[500010];
void init() {
    for (int i = 0; i < 500010; ++i)
        parent[i] = i;
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[py] = px;
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> c;
        for (int j = 0; j < c; ++j) {
            cin >> k[j];
        }
        for (int j = 1; j < c; ++j) {
            int x = k[j];
            int y = k[j - 1];
            if(find(x) != find(y))
                merge(x,y);
        }
    }

    for (int i = 1; i <= n; ++i) 
        cnt[find(i)]++;
    
    for (int i = 1; i <= n; ++i)
        cout << cnt[find(i)] << " ";
    cout << "\n";
    return 0;
}

