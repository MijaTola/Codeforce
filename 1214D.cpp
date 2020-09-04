#include <bits/stdc++.h>

using namespace std;

int n,m;
string c[1000010];
int d[1000010];
int dx[] = {0,1};
int dy[] = {1,0};
int mx = 0;
map<pair<int,int>, int> dp;

int f(int x, int y, int dis = 1) {
    mx = max(mx, dis);
    if(x == n - 1 and y == m - 1) return 1;
    if(dp.count({x,y})) return  dp[make_pair(x,y)];
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if(u >= 0 and u < n and v >= 0 and v < m and c[u][v] == '.') {
            ans |= f(u, v, dis + 1);
        }
    }
    
    if(ans) d[dis]++;
    
    return dp[make_pair(x,y)] = ans;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> c[i];

    if(!f(0, 0)) return cout << "0\n", 0;
    int ans = 1e9;
    for (int i = 2; i < mx; ++i) {
        ans = min(ans, d[i]);
    }


    cout << ans << "\n";


    return 0;
}

