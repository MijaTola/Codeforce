#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > edges;
set< pair<int,int> > dom;
int val[10];
int n,m;
int mx = 0;
void f(int pos, vector<int> p) {
    if(pos == 6) {
        for (int i = 0; i < (int)p.size(); ++i)
            val[p[i]] = i + 1;
        int ans = 0;
        set<pair<int,int> > vis;
        for (int i = 0; i < m; ++i) {
            int x = val[edges[i].first];
            int y = val[edges[i].second];
            if(dom.count({x,y}) and !vis.count({x,y})) {
                ans++;
                vis.insert({x,y});
                continue;
            }
            if(dom.count({y,x}) and !vis.count({y,x})) {
                ans++;
                vis.insert({y,x});
                continue;
            }
        }
        mx = max(ans, mx);
        return;
    }

    for (int i = 0; i <= n; ++i) {
        p.push_back(i);
        f(pos + 1, p);
        p.pop_back();
    }
}
int main() {
    dom.insert({1,1});
    dom.insert({1,2});
    dom.insert({1,3});
    dom.insert({1,4});
    dom.insert({1,5});
    dom.insert({1,6});
    dom.insert({2,2});
    dom.insert({2,3});
    dom.insert({2,4});
    dom.insert({2,5});
    dom.insert({2,6});
    dom.insert({3,3});
    dom.insert({3,4});
    dom.insert({3,5});
    dom.insert({3,6});
    dom.insert({4,4});
    dom.insert({4,5});
    dom.insert({4,6});
    dom.insert({5,5});
    dom.insert({5,6});
    dom.insert({6,6});

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        edges.push_back({x,y});
    }

    f(0, {});
    cout << mx << "\n";
    return 0;
}

