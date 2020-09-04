#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        long long ans = 1e10;
        for (int x: {-1, 0, 1}) {
            for (int y: {-1, 0, 1}) {
                for (int z: {-1, 0, 1}) {
                    long long da = a + x;
                    long long db = b + y;
                    long long dc = c + z;
                    long long cur = abs(da - db) + abs(da - dc) + abs(db - dc);
                    ans = min(cur, ans);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

