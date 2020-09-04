#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        long long x,y,a,b;
        cin >> x >> y >> a >> b;

        long long ans = 0;
        long long a2 = (x + y) * a;
        long long mn = min(x,y);
        ans += mn * b;
        x -= mn;
        y -= mn;
        ans += y * a;
        ans += x * a;
        cout << min(ans, a2) << "\n";

    }
    return 0;
}

