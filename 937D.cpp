#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
bool vis[200010][2];
int dp[200010][2];
int s;
bool cycle;
bool f(int u,bool turn) {
    if(G[u].size() == 0 and turn and u != s) return 1;
    if(G[u].size() == 0 and turn and u == s) return 0;
    if(G[u].size() == 0 and !turn) return 0;
    if(dp[u][turn] != -1) return dp[u][turn];
    if(vis[u][turn]){
        cycle = 1;
        return 0;
    }
    vis[u][turn] = 1;
    bool ans = 0;
    for (int v: G[u]) 
        ans |= f(v,!turn);
    return dp[u][turn] = ans;
}

void r(int u, bool turn) {
    if(G[u].size() == 0 and turn and u != s) return;
    if(G[u].size() == 0 and turn and u == s) return;
    if(G[u].size() == 0 and !turn) return;
    if(vis[u][turn]) return;
    vis[u][turn] = 1;

    for (int i = G[u].size() - 1; i >= 0; i--) {
        int v = G[u][i];
        if(f(v,!turn) == 1) {
            cout << v << " ";
            r(v,!turn);
            return;
        }
    }
}
int main(){
    memset(dp, -1,sizeof dp);
    memset(vis,0,sizeof vis);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        while(x--) {
            int y; cin >> y;
            G[i].push_back(y);
        }
    }
    cin >> s;
    cycle = 0;
    bool ans = f(s,0);
    if(!ans and !cycle) return cout << "Lose\n",0;
    if(!ans and cycle) return cout << "Draw\n",0;
    memset(vis,0,sizeof vis);
    cout << "Win\n";
    cout << s << " "; r(s,0);
    cout << "\n";
    return 0;
}

