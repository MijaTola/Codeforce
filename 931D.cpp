#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
int v[100010];

int dfs(int u) {
    if(G[u].size() == 0) return 1;
    int ans = 0;
    
    vector<int> a;
    
    for (int vv: G[u]){
        int x = dfs(vv);
        ans += x;
        a.push_back(x);
    }
    if(G[u].size() % 2 == 0) return 1;
    sort(a.begin(),a.end());
    int dif = 0;
    int last = 0;
    int cur = 0;
    if(ans % G[u].size() != 0) {
        for (int i = 0; i < (int)G[u].size(); ++i) {
            if(i % 2 == 0){
                dif = v[i] - last;
                last += dif;
                ans += dif;
            }
        }
    }
    return ans + 1;
}
int main(){
    
    int n; cin >> n;

    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        G[x].push_back(i);
    }
    
    cout << dfs(1) << "\n";
    return 0;
}

