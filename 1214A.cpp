#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, dd,ee;
    cin >> n >> dd >> ee;
    
    int ans = 1e9;
    for (int i = 0; i <= n; ++i) {
        int left = i;
        int right = n - i;
        left /= dd;
        right /= ee;
        right /= 5;
        int total = left * dd + right * ee * 5;
        ans = min(ans, n - total);
    }
    cout << ans << "\n";
    return 0;
}

