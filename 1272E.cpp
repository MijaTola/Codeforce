#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int d[200010];
vector<int> G[200010];

int main() {
    
    scanf("%d", &n);
    queue<int> q;
    for (int i = 0; i < 200010; ++i)
        d[i] = 1e9;
    
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    for (int i = 0; i < n; ++i) {
        if(i + v[i] < n) {
            G[i + v[i]].push_back(i);
            if(v[i] % 2 != v[i + v[i]] % 2) {
                d[i] = 1;
                q.push(i);
            }
        }
        if(i - v[i] >= 0) {
            G[i - v[i]].push_back(i);
            if(v[i] % 2 != v[i - v[i]] % 2) {
                d[i] = 1;
                q.push(i);
            }
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: G[u]) {
            if(d[u] + 1 < d[v]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", d[i] != 1e9 ? d[i] : -1);
    puts("");
    return 0;
}
