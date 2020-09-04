#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
    cin >> n;
    vector<pair<int,int> > v(n);
    map<int,int> mx;
    map<int, long long> sum;
    map<int, vector<int> > mp;


    for (auto &p: v)
        cin >> p.first;

    for (auto &p: v)
        cin >> p.second;

    sort(v.begin(), v.end());
    sort(v.begin(), v.end());

    for (auto p: v) {
        mx[p.first] = max(mx[p.first], p.second);
        mp[p.first].push_back(p.second);
    }

    priority_queue<int> q;
    long long ts = 0, ans = 0;
    
    while(!mx.empty()) {
        auto p = *mx.begin();
        int cur = p.first;
        for (auto x: mp[cur]) {
            q.push(x);
            ts += x;
        }
        if(!q.empty()) ts -= q.top();
        q.pop();
        ans += ts;
        if(!q.empty()) mx[cur + 1] = 1;
        mx.erase(mx.begin());
    }
    
    cout << ans << "\n";


    return 0;
}

