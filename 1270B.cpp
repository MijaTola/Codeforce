#include <bits/stdc++.h>

using namespace std;

int n,t;
int v[200010];

int main() {

    cin >> t;

    while(t--) {
        cin >> n;

        for (int i = 0; i < n; ++i) 
            cin >> v[i];
        
        int ans = -1, ans2 = -1;
        for (int i = 0; i < n - 1; ++i) {
            if(abs(v[i] - v[i + 1]) >= 2) {
                ans = i, ans2 = i + 1;
                break;
            }
        }
        
        if(ans == -1) cout << "NO\n";
        else cout << "YES\n" << ans + 1 << " " << ans2 + 1 << "\n";
        
    }
    return 0;
}

