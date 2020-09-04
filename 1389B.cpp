#include <bits/stdc++.h>

using namespace std;

int v[100010];
int a[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

        int n,k,z;
        cin >> n >> k >> z;
       
        for (int i = 1; i <= n; ++i)
            cin >> v[i];

        for (int i = 1; i <= n; ++i) {
            a[i] = v[i];
            a[i] += a[i - 1];
        }

        long long ans = 0;

        for (int i = 2, moves = 1; i <= n and moves <= k; ++i, moves++) {
            long long cur = a[i];
            int left = k - moves;
            for (int j = 0; j < z and left > 0; ++j, left--) {
                cur += v[i - 1];
                left--;
                if(left) cur += v[i];
                else break;
            }
            if(left) cur += a[i + left] - a[i];
            ans = max(ans, cur);
        }
        
        cout << ans << "\n";

    }
    return 0;
}

