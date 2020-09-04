#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
    
        int mx = -1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int a,b;
            cin >> a >> b;
            mx = max(mx, a - b);
            cur = max(cur, a);
        }
        x -= cur;
        
        if(x <= 0) cout << "1\n";
        else if(mx <= 0) {
            cout << "-1\n";
            continue;
        }
    
        else cout << (x + mx - 1) / mx + 1 << "\n";
       
    }
    return 0;
}

