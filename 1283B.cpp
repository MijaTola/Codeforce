#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;

        int dv = n / k;
        int md = n % k;
        int mid = k / 2;
    
        
        int ans = dv * k;

        if(md >= mid) ans += mid;
        else ans += md;

        cout << ans << "\n";

    }
    return 0;
}

