#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<int> G[200010];
int in[200010];
int out[200010];
int pos;
vector<int> s;
void dfs(int u) {
    s.push_back(u);
    //cout  << u << " " << pos << "\n";
    in[u] = pos++;
    for (int v: G[u]) {
        dfs(v);
    }
    out[u] = pos - 1;
}
int main(){

    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        G[x].push_back(i);
    }
    pos = 0;
    dfs(1);
    while(q--) {
        int u,k;
        cin >> u >> k;
        int start = in[u];
        int end = out[u];
        if(end - start + 1< k) cout << "-1\n";
        else cout << s[start + k - 1] << "\n";
        
    }
    return 0;
}

