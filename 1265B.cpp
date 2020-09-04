#include <bits/stdc++.h>

using namespace std;

long long v[200010];
int b[200010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n ; ++i) {
            cin >> v[i];
            b[v[i]] = i;
            v[i] += v[i - 1];
        }
        
        int l = b[1], r = b[1];
        string ans = "";
        for (long long i = 1; i <= n; ++i) {
            long long cur = i * (i + 1) / 2;
            l = min(b[i], l);
            r = max(b[i], r);
            if(v[r] - v[l - 1] == cur) ans += "1";
            else ans += "0";
        }
       
        cout << ans << "\n";

    }
    return 0;
}

