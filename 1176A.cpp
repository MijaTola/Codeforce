#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        long long n;
        cin >> n;
        int ans = 0;
        while(n != 1) {
            if(n % 2 == 0) n /= 2;
            else if(n % 3 == 0) n = (2 * n) / 3;
            else if(n % 5 == 0) n = (4 * n) / 5;
            ans++;
            if(ans > 1000) break;
        }
        if(ans > 1000) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}


