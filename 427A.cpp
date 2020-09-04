#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        total += x;
        ans += total < 0;
        total = max(total,0);
    }
    cout << ans << "\n";
    return 0;
}

