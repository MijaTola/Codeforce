#include <bits/stdc++.h>

using namespace std;

vector<int> G[10010];
int color[10010];
int f(int u, int col, int p) {
    int ans = col != color[u];
    for (int v: G[u]) {
        if(p == v) continue;
        ans += f(v, color[u], u);
    }
    return ans;
}
int main() {
    
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }


    for (int i = 1; i <= n; ++i)
        cin >> color[i];

    cout << f(1, 0, 1) << "\n";
    return 0;
}

