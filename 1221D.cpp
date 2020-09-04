#include <bits/stdc++.h>
 
using namespace std;
 
int n;
long long a[300010];
long long b[300010];
long long dp[300010][3];
long long f(int pos, int last) {
    if(pos == n) return 0;
    long long &ans = dp[pos][last];
    if(ans != -1) return ans;
    ans = 1e18;
    for (int i = 0; i < 3; ++i) {
        if(a[pos - 1] + last == a[pos] + i) continue;
        ans = min(ans, f(pos + 1, i) + b[pos] * i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
 
        cin >> n;
        for (int i = 0; i < n; ++i) 
                dp[i][0] = dp[i][1] = dp[i][2] = -1;

        for (int i = 0; i < n; ++i) 
            cin >> a[i] >> b[i];
        
        cout << f(0, 0) << "\n";
    }
    return 0;
}

