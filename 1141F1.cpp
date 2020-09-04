#include <bits/stdc++.h>

using namespace std;

int n;
int v[1500];
int dp[2200000][51];

map<int, vector<pair<int,int> > > mp;
vector<pair<int,int> > b;

int f(int pos, int last) {
    if(pos == (int)b.size()) return 0;
    int &ans = dp[pos][last];
    if(ans != -1) return ans;
    ans = 0;
    if(b[pos].first > last) 
        ans = max(f(pos + 1, b[pos].second) + 1, ans);    
    ans = max(ans,f(pos + 1, last));
    return ans;
}

void r(int pos, int last) {
    if(pos >= (int)b.size()) return;
    int ans1 = 0;
    if(b[pos].first > last) ans1 = f(pos + 1, b[pos].second) + 1;
    int ans2 = f(pos + 1, last);
    if(ans1 >= ans2 and b[pos].first > last) {
        cout << b[pos].first << " " << b[pos].second << "\n";
        r(pos + 1, b[pos].second);
    } else r(pos + 1, last);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    for (int i = 1; i <= n; ++i)
        v[i] += v[i - 1];

    for (int i = 1; i <= n; ++i) 
        for (int j = i; j <= n; ++j) {
            int cur = v[j] - v[i - 1];
            mp[cur].push_back({i,j});
        }
    
    int ans = 0;
    int id = 0;
    for (auto &p: mp) {
        b = p.second;
        sort(b.begin(), b.end());
        memset(dp, -1, sizeof dp);
        if(f(0,0) > ans) {
            ans = f(0,0);
            id = p.first;
        }
    }
    cout << ans << "\n";
    b = mp[id];
    f(0,0);
    r(0,0);
    return 0;
}

