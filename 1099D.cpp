#include <bits/stdc++.h>

using namespace std;

int n;
int s[100010];
vector<int> G[100010];
int ans[100010];
bool flag;
void dfs(int u, int sum) {
    if(s[u] != -1) {
        ans[u] = s[u] - sum;
        flag &= ans[u] >= 0;
        for (int v: G[u]) 
            dfs(v, s[u]);
        
    } else {
        if(!G[u].size()) {
            ans[u] = 0;
            return;
        }
        ans[u] = 1e9;
        for (int v: G[u]) 
            ans[u] = min(ans[u], s[v] - sum);
        flag &= ans[u] >= 0;
        for (int v: G[u]) 
            dfs(v, ans[u] + sum);
    }
}

int main() {

    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        G[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i) 
        cin >> s[i];

    flag = 1;
    dfs(1,0);
    if(!flag) return cout << "-1\n",0;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += ans[i];
    }
    cout << sum << "\n";
    
    return 0;
}

