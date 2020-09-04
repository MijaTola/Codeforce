#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<pair<long long,long long> > v;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({y,x});
    }

    sort(v.begin(), v.end(), cmp);
    
    priority_queue<int> q;
    long long sum = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if((int)q.size() < k) {
            sum += v[i].second;
            q.push(-v[i].second);
        } else {
            sum -= -q.top();
            q.pop();
            sum += v[i].second;
            q.push(-v[i].second);
        }
        ans = max(ans, sum * v[i].first);
    }
    cout << ans << "\n";
    return 0;
}

