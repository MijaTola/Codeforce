#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long a,b,x,y;
        cin >> a >> b >> x >> y;
        x++,y++;
        long long ans = (y - 1) * a;
        ans = max(ans, (b - y) * a);
        ans = max(ans, (x - 1) * b);
        ans = max(ans, (a - x) * b);
        cout << ans << "\n";

    }
    return 0;
}

