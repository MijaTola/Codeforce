#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt += x & 1;
        }
        
        if(cnt) {
            if(n & 1) cout << "YES\n";
            else if(n - cnt) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
    return 0;
}

