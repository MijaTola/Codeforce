#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > v;
int main() {
    int n,l,a;
    cin >> n >> l >> a;

    for (int i = 0; i < n; ++i) {
        int t,li;
        cin >> t >> li;
        v.push_back({t,li});
    }
    v.push_back({0,0});
    v.push_back({l,0});

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i < (int)v.size(); ++i) {
        int ini = v[i].first;
        int end = v[i - 1].first + v[i - 1].second;
        int dif = ini - end;
        ans += dif / a;
    }
    cout << ans << "\n";
    return 0;
}

