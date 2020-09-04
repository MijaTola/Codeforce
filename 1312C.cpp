#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        
        vector<long long> b(n);

        for (long long &x: b)
            cin >> x;

        sort(b.begin(), b.end());


        long long p = 1;
        
        priority_queue<long long> q;

        while(p <= LLONG_MAX/ (long long)k) {
            q.push(p);
            p *= (long long)k;
        }
        
        bool flag = 1;
        for (int i = 0; i < n;++i) {
            queue<long long> q2;
            while(b[i] and !q.empty()) {
                long long u = q.top();
                q.pop();
                if(u > b[i]) {
                    q2.push(u);
                    continue;
                }
                b[i] -= u;
            }
            if(b[i]) flag = 0;
            
            while(!q2.empty()) {
                q.push(q2.front());
                q2.pop();
            }   
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

