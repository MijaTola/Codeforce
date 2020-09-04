#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int ab = a + b + i;
        int ac = a + c + i;
        int bd = b + d + i;
        int dc = c + d + i;
        int mx = max(ab, max(ac, max(bd, dc)));
        int mn = min(ab, min(ac, min(bd, dc)));
        int dif = max(0,(mx - mn));
        ans += max((n - dif),0);
    }
    cout << ans << "\n";
    return 0;
}

