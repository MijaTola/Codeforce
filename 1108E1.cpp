#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[100010];
int b[100010];

vector<pair<int,int> > seg;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        x--,y--;
        seg.push_back({x,y});
    }

    if(n == 1) return cout << "0\n0\n",0;
    int ans = -1e9;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < n; ++i)
            b[i] = v[i];
        for (int j = 0; j < m; ++j) {
            int x = seg[j].first;
            int y = seg[j].second;
            if(!(x <= i and i <= y)) {
                for (int k = x; k <= y; ++k)
                    b[k]--;
            }
        }
        int mn = 1e9;
        int mx = -1e9;
        for (int j = 0; j < n; ++j) {
            mx = max(mx, b[j]);
            mn = min(mn, b[j]);
        }
        if((mx - mn) > ans) {
            ans = mx - mn;
            id = i;
        }
    } 
    int mn = 1e9;
    int mx = -1e9;
    for (int j = 0; j < n; ++j) {
        mx = max(mx, v[j]);
        mn = min(mn, v[j]);
    }
    if((mx - mn) > ans) {
        ans = mx - mn;
        cout << ans << "\n";
        cout << "0\n";
        return 0;
    }
    cout << ans << "\n";
    vector<int> as;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x = seg[i].first;
        int y = seg[i].second;
        if(!(x <= id and id <= y)) {
            cnt++;
            as.push_back(i);
        }
    }

    cout << cnt << "\n";
    for (int x: as)
        cout << x + 1 << " ";
    cout << "\n";
    return 0;
}

