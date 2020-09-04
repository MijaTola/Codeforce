#include <bits/stdc++.h>

using namespace std;

int n;
int v[4];

int main() {
    int t;
    cin >> t;
    while(t--) {
        v[0] = v[1] = v[2] = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[x % 3]++;
        }
        int ans = v[0];
        int mx = 0;
        for (int i = 0; i <= v[2]; ++i) {
            int a = i;
            int b = v[2] - i;
            int mn = min(a, v[1]);
            int left = v[1] - min(a, v[1]);
            mx = max(mx, left / 3 + mn + b / 3);
        }
        cout << ans + mx << "\n";
    }
 
    return 0;
}

