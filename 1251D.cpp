#include <bits/stdc++.h>

using namespace std;

int n;
long long s;

vector<pair<int,int> > v;

bool ver(long long k) {
    int up = 0;
    int down = 0;
    int mid = (n + 1)  / 2;
    long long sum = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        if(v[i].second < k) {
            down++;
            sum += v[i].first;
        } else if(v[i].first > k) {
            up++;
            sum += v[i].first;
        } else {
            q.push(-v[i].first);
        }
    }
    if(up >= mid) return 1;
    if(down >= mid) return 0;
    
    while(down + 1 < mid and !q.empty()) {
        sum -= q.top();
        q.pop();
        down++;
    }

    sum += q.size() * k;
    
    return s >= sum and down + 1 == mid and q.size();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        long long a = 0, b = s + 1;
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(ver(mid)) a = mid;
            else b = mid;
        }
        cout << a << "\n";
    }
    return 0;
}

