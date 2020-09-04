#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<int> b;
int v[200010];
map<int,int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] > 0) a.push_back(v[i]);
        if(v[i] < 0) b.push_back(-v[i]);
        mp[abs(v[i])]++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        v[i] = abs(v[i]);
        long long p1 = upper_bound(a.begin(), a.end(), v[i]) - a.begin();
        long long p2 = upper_bound(a.begin(), a.end(), 2 * v[i]) - a.begin();
        ans += abs(p2 - p1);
        p1 = upper_bound(b.begin(), b.end(), v[i]) - b.begin();
        p2 = upper_bound(b.begin(), b.end(), 2 * v[i]) - b.begin();
        ans += abs(p2 - p1);
    }

    for (auto p: mp)
        ans += (p.second == 2);
    cout << ans << "\n";
    return 0;
}

