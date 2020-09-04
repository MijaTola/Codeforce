#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int n;

int ver(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    pair<int,int> ab = {a.first - b.first, a.second - b.second};
    pair<int,int> cb = {c.first - b.first, c.second - b.second};
    return ab.first * cb.second - ab.second * cb.first;
}

int main() {
    cin >> n;

    for (int i = 0; i <=  n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    int ans = 0;

    for (int i = 0; i < v.size() - 2; ++i) 
        ans += ver(v[i], v[i + 1], v[i + 2]) < 0;
    
    cout << ans << "\n";
    return 0;
}

