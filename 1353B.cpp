#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        
        int n,k;
        cin >> n >> k;
        priority_queue<int> a,b;
        
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push(-x);
        }

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b.push(x);
        }

        long long ans = 0;
        while(k--) {
            if(-a.top() <= b.top()) {
                ans += b.top();
                a.pop();
                b.pop();
            } else break;
        }
        while(!a.empty()) {
            ans += -a.top();
            a.pop();
        }

        cout << ans << "\n";
    }
    return 0;
}

