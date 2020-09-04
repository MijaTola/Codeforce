#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<pair<pair<int,int>,pair<int,int> > > v;
vector<pair<pair<int,int>, pair<int,int> > > b[100010];
pair<long long, int> able[100010];
long long dp[100010][210];

long long f(int pos, int dm) {
    if(pos == n + 1) return 0;
    long long &ans = dp[pos][dm];
    if(ans != -1) return ans;
    ans = 1e15;
    if(dm) ans = min(ans, f(pos + 1, dm - 1));
    if(able[pos].first == -1) ans = min(ans, f(pos + 1, dm));
    else ans = min(ans, f(able[pos].second + 1, dm) + able[pos].first);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int s,t,d,w;
        scanf("%d %d %d %d", &s, &t, &d, &w);
        v.push_back({{s,t},{d,w}});
    }

    sort(v.begin(),v.end());
    for (int i = 0; i < k; ++i) {
        int st = v[i].first.first;
        b[st].push_back(v[i]);
    }

    priority_queue<pair<int,pair<int,int> > > q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)b[i].size(); ++j) 
            q.push({b[i][j].second.second,{b[i][j].second.first, b[i][j].first.second}});
        int dw = -1;
        int dd = -1;
        int mx = -1;
        while(mx < i and !q.empty()) {
            dw = q.top().first;
            dd = q.top().second.first;
            mx = q.top().second.second;
            q.pop();
        }
        if(mx >= i)q.push({dw,{dd,mx}});
        else dw = dd = mx = -1;
        able[i] = {dw, dd};
    }
    printf("%lld\n", f(1, m));
    return 0;
}

