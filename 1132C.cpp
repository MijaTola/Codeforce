#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<pair<int,int> > v;

int dp[5010][5010][2];
int f(int pos,int last, int del) {
    if(pos == q) {
        if(del == 0) return 0;
        else return -1e9;
    }
    
    int &ans = dp[pos][last][del];

    if(ans != -1) return ans;
    ans = -1e9;
    if(last >= v[pos].second) {
        if(del) ans = max(ans, f(pos + 1, last, del - 1));
        ans = max(ans, f(pos + 1, last, del));
        return ans;
    }
    if(del > 0) {
        ans = max(ans, f(pos + 1, last, del - 1));
        int mx = max(last + 1, v[pos].first);
        int dif = (v[pos].second - mx) + 1;
        ans = max(ans, f(pos + 1, v[pos].second, del) + dif);
    } else {
        int mx = max(last + 1, v[pos].first);
        int dif = (v[pos].second - mx) + 1;
        ans = max(ans, f(pos + 1, v[pos].second, del) + dif);
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
     }
    sort(v.begin(), v.end());
    cout << f(0,0,2) << "\n";
    return 0;
}
