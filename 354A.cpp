#include <bits/stdc++.h>
using namespace std;


int n, l, r, ql, qr;
int v[100010];
int s[100010];

int main(){

    cin >> n >> l >> r >> ql >> qr;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[i+1] = s[i] + v[i];
    }

    int ans = INT_MAX;

    for (int i = 0; i <= n; i++) {
        int cur = 0;

        cur += l * s[i];
        cur += r * (s[n] - s[i]);

        int ur = n - i;
        if(ur > i) cur += qr * (ur - i - 1);
        if(i > ur) cur += ql * (i - ur - 1);

        ans = min(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}
