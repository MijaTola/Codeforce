#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        priority_queue<pair<int,int> > q;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            q.push({x, 1});
        }

        int ans = 0;
        while(q.size() >= 2) {
            int u = q.top().first;
            int x = q.top().second;
            q.pop();
            if(!q.empty() and u == q.top().first) {
                auto p = q.top();
                q.pop();
                q.push({u, x + p.second});
            } else {
                if(u % 2 == 0) {
                    ans++;
                    q.push({u / 2, x});
                }
            }
        }

        while(!q.empty() and q.top().first % 2 == 0) {
            ans++;
            int u = q.top().first;
            q.pop();
            u /= 2;
            if(u % 2 == 0) q.push({u, 0});
        }
        cout << ans << "\n";
    }
    return 0;
}

