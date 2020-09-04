#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;

        int dif = abs(a - b);

        int ans = 0;

        ans += dif / 5;
        dif %= 5;
        ans += dif / 2;
        ans += dif % 2;
        cout << ans << "\n";
    }

    return 0;
}

