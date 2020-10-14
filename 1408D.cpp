#include <bits/stdc++.h>

using namespace std;

int v[2000000];
int main() {

    int n,m;
    cin >> n >> m;

    vector<pair<int,int> > a(n),b(m);

    for (auto &p: a)
        cin >> p.first >> p.second;

    for (auto &p: b)
        cin >> p.first >> p.second;

 
    for (auto p1: a) 
        for (auto p2: b) {
            if(p1.first <= p2.first) {
                int val = p2.first - p1.first;
                v[val] = max(v[val], p2.second - p1.second + 1);
            }
        }

    int ans = 1e9;
    int mx = 0;
    for (int i = 2000000; i >= 0; i--) {
        mx = max(v[i], mx);
        ans = min(ans, mx + i);
    }

    cout << ans << "\n";

    return 0;
}
