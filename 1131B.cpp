#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int x = 0, y = 0;
    long long ans = 1;
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(a == x and b == y) continue;
        long long mn = min(a, b);
        long long mx = max(x, y);
        ans += max(0ll, mn - mx + 1);
        if(x == y) ans--;
        x = a, y = b;
    }
    cout << ans << "\n";
    return 0;
}
