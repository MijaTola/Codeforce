#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k,t;
    cin >> n >> k >> t;

    int lim = n - k;
    if(t <= k) cout << t << "\n";
    else if(t > k + lim) {
        int df = t - (k + lim);
        int ans = k - df;
        cout << max(0, ans)  << "\n";
    } else {
        cout << k << "\n";
    }
    return 0;
}

