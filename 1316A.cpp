#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;
        
        int x;
        cin >> x;
        
        for (int i = 1; i < n; ++i) {
            int y;
            cin >> y;
            x += y;
        }

        cout << min(x, m) << "\n";
        
    }
    return 0;
}

