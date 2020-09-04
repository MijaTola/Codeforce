#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<pair<int,int> > v[200010];
vector<pair<int,pair<int,int> > > b;

int bs(int needed, int r) {
    int a = -1;
    int b = v[needed].size();
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(v[needed][mid].first > r) b  = mid;
        else a = mid;
    }
    return b;
}

int main() {
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        int l,r,c;
        cin >> l >> r >> c;
        v[(r - l + 1)].push_back(make_pair(l,c));
        b.push_back(make_pair(c, make_pair(l,r)));
    }
    

    for (int i = 0; i < 200010; ++i) {
        int mn = 1e9;
        sort(v[i].begin(), v[i].end());
        for (int j = v[i].size() - 1; j >= 0; j--) {
            mn = min(mn, v[i][j].second);
            v[i][j].second = mn;
        }
    }
    
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int l = b[i].second.first;
        int r = b[i].second.second;
        int c = b[i].first;
        int dx = (r - l + 1);
        if(dx > x) continue;
        int needed = x - dx;
        int pos = bs(needed, r);
        if(pos == -1 or pos == (int)v[needed].size()) continue;
        ans = min(ans, c + v[needed][pos].second);
    }
    if(ans == INT_MAX) puts("-1");
    else cout << ans << "\n";
    return 0;
}
