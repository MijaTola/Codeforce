#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int main() {
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    auto check2 = [] (int x, vector<pair<int,int> > &b) {
        for (auto p: b) {
            if(p.first == x or p.second == x) continue;
            return 0;
        }
        return 1;
    };

    auto check = [check2] (int x) -> bool {
        vector<pair<int,int> > b;
        for (auto p: v) {
            if(p.first == x or p.second == x) continue;
            b.push_back(p);
        }
        if(b.empty()) return 1;
        return check2(b[0].first, b) or check2(b[0].second, b);
    };

    puts(check(v[0].first) or check(v[0].second) ? "Yes" : "No");

    return 0;
}
