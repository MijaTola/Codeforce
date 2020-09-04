#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        
        int mx = 0, mx2 = 0;
        for (int i = 0; i < a; ++i) {
            int x;
            cin >> x;
            mx = max(mx, x);
        }

        for (int i = 0; i < b; ++i) {
            int x;
            cin >> x;
            mx2 = max(mx2, x);
        }

        if(mx > mx2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

