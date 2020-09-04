#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> G[200010];
int ans = 0;
int dfs(int u, int parent, int last) {
    int sum = last;
    for (auto v: G[u]) {
        if(v.first == parent) continue;
        sum += dfs(v.first, u, v.second);
    }
    cout << u << " " << sum << " wtf\n";
    cout << (sum * (sum - 1)) / 2 << " cur\n";
    if(!last) {
        sum++;
        cout << sum << " to combi\n";
        cout << sum * (sum - 1) / 2 << " sum\n";
        ans += (sum * (sum - 1)) / 2;
        return 0;
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x,y,c;
        cin >> x >> y >> c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }

    cout << dfs(1,0,0) << "\n";
    return 0;
}

