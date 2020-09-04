#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    int c = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] == mx) c++;
        else ans = max(ans, c), c = 0;
    }
    ans = max(ans, c);
    cout << ans << "\n";
    return 0;
}

