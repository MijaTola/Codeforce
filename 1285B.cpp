#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {

    int t;
    cin >> t;
    while(t--) {
        
        int n;
        cin >> n;
        
        long long a = 0;
        long long s = 0;
        long long ans = -1e9;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[i] = x;
            a += x;
        }

        for (int i = 0; i < n - 1; ++i) {
            s += v[i];
            s = max(s, 0ll);
            ans = max(ans, s);
        }
        s = 0;
        for (int i = 1; i < n; ++i) {
            s += v[i];
            s = max(s, 0ll);
            ans = max(ans, s);
        }
        puts(a > ans ? "YES" : "NO");
    }
    return 0;
}

