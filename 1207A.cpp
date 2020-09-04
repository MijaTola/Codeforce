#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n,p,f,h,c;
        cin >> n >> p >> f >> h >> c;
        
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int dp = i / 2;
            int dc = (n - i) / 2;
            ans = max(ans,  min(dp, p) * h + min(dc, f) * c);
        }
        cout << ans << "\n";
    }
    return 0;
}

