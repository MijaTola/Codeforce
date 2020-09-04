#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int v[100010];
vector<pair<int,int> > b;
int dp[2010][200010];

int f(int pos, int cur) {
    if(pos >= k) return 0;
    
    int &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 1e9;

    for (int i = cur; i < m; ++i) {
        if(pos + b[i].first - 1 >= k or pos + b[i].second - 1 >= k) continue;
        ans = min(ans, f(pos + b[i].first, i + 1) + v[pos + b[i].first - 1] - v[pos + b[i].second - 1]);
    }
    for (int i = pos; i < k; ++i) 
        ans = min(ans, f(i + 1, cur) + (v[i] - v[pos - 1]));
        
    return ans;
}


int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v, v + n);

    for (int i = 1; i < n; ++i)
        v[i] += v[i - 1];

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        b.push_back({x,y});
    }
    
    cout << f(0,0) << "\n";
    return 0;
}
