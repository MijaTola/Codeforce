#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
bool vis[200010];
string s;
int a[30];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    a[s[u] - 'a']++;
    for (int v: G[u]) 
        dfs(v);
    
}
int main() {

    int t;
    cin >> t;

    while(t--) {

        int n,k;
        cin >> n >> k >> s;
    
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
            vis[i] = 0;
        }

        int l = 0, r = n - 1;

        while(l < r) {
            G[l].push_back(r);
            G[r].push_back(l);
            l++, r--;
        }

        for (int i = 0; i < n; ++i) {
            if(i + k >= n) break;
            G[i].push_back(i + k);
            G[i + k].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                memset(a, 0, sizeof a);
                dfs(i);
                int mx = -1;
                int sum = 0;
                for (int j = 0; j < 30; ++j) {
                    mx = max(mx, a[j]);
                    sum += a[j];
                }
                    
                ans += sum - mx;
            }
        }

        cout << ans << "\n";

    }
    return 0;
}

