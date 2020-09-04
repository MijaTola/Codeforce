#include <bits/stdc++.h>

using namespace std;

long long ans[500010];
int main() {
    

    for (int i = 3; i < 500010; ++i) {
        long long dv = (i + 1) / 2;
        ans[i] += ans[i - 2] + (dv - 1) * (i * 4LL - 4);
    }

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}

