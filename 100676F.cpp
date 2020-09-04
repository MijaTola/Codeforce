#include <bits/stdc++.h>

using namespace std;

long long power[50010];
const int mod = 1e9 + 7;
vector<int> G[50010];
bool vis[50010];
set<char> st;
int n,m;
string s;

bool dfs(int u) {
    vis[u] = 1;
    bool ans = s[u] == '?';
    if(s[u] != '?') st.insert(s[u]);

    for (int v: G[u]) 
        if(!vis[v]) ans |= dfs(v);
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    power[0] = 1;
    for (int i = 1; i < 50010; ++i)
        power[i] = (26 * power[i - 1]) % mod;

    int t;
    cin >> t;

    while(t--) {
        memset(vis, 0, sizeof vis);

        for (int i = 0; i < 50010; ++i)
            G[i].clear();

        cin >> n >> m >> s;
        int l = 0, r = n - 1;
        while(l < r) {
            G[l].push_back(r);
            G[r].push_back(l);
            l++,r--;
        }
        
        for (int i = 0; i < m; ++i) {
            int x,y;
            cin >> x >> y;
            x--, y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        bool flag = 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                st.clear();
                bool cur = dfs(i);
                if(cur and st.size() == 0)  cnt++;
                flag &= (int)st.size() <= 1;

            }
        }
        if(!flag) {
            cout << "0\n";
            continue;
        } 
        cout << power[cnt] << "\n";
    }
    return 0;
}

