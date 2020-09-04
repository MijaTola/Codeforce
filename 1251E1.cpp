#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;

int main() {

    int t;
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            v.push_back({x,-y});
        }
    
        sort(v.begin(), v.end());

        priority_queue<int> q;
        
        long long ans = 0;
        long long cur = 0;

        for (int i = n - 1; i >= 0; i--) {
            q.push(v[i].second);
            if(cur + i >= v[i].first) continue;
            cur++;
            ans -= q.top();
            q.pop();
        }

        cout << ans << "\n";
    }
    return 0;
}

