#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int, char> > G[110];
int dp[110][110][2][30];

int f(int u, int t, int turn, int last) {
    char cur = last + 'a';
    int &ans = dp[u][t][turn][last];
    if(ans != -1) return ans;
    ans = 0;
    if(turn) {
        if(G[u].size() == 0) return 0;

        for (auto p: G[u]) {
            int v = p.first;
            char vv = p.second;
            if(vv < cur) continue;
            if(!f(v, t, 1 - turn, vv - 'a')) {
                return ans = 1;
            }
        }

    } else {
        if(G[t].size() == 0) return ans = 0;

        for (auto p: G[t]) {
            int v = p.first;
            char vv = p.second;
            if(vv < cur) continue;
            if(!f(u, v, 1 - turn, vv - 'a'))  return  ans = 1;
        }
    }
    return ans = 0;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        G[x].push_back({y,c});
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(f(i,j,1,0)) printf("A");
            else printf("B");
        }
        puts("");
    }


    return 0;
}

