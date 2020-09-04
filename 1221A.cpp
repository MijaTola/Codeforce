#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        priority_queue<int> q;
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            q.push(-x);
        }
        
        bool flag = 0;
        while(!q.empty() and q.size() >= 2) {
            int u = -q.top();
            q.pop();
            int v = -q.top();
            q.pop();
            flag |= (u == 2048);
            flag |= (v == 2048);
            if(u == v) 
                q.push(-(u + v));
            else q.push(-v);
        }

        while(!q.empty()) {
            int u = -q.top();
            q.pop();
            flag |= (u == 2048);
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

