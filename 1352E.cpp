#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> v(n),a(n + 1),b,c(n + 1);

        for (int &x: v) {
            cin >> x;
            a[x]++;
        }

        for (int i = 0; i < n; ++i) {
            int sum = v[i];
            for (int j = i + 1; j < n; ++j) {
                sum += v[j];
                if(sum <= n and a[sum] and !c[sum]) {
                    b.push_back(sum);
                    c[sum] = 1;
                }
            }
        }
        
        int ans = 0;
        for (int x: b)  ans += a[x];
        cout << ans << "\n";
    }
    return 0;
}

