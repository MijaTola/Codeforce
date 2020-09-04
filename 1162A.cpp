#include <bits/stdc++.h>

using namespace std;

int n,h,m;

int v[55];
int main() {
    cin >> n >> h >> m;
    
    for (int i = 0; i < n; ++i) 
        v[i] = h;
    
    for (int i = 0; i < m; ++i) {
        int l,r,c;
        cin >> l >> r >> c;
        l--,r--;
        for (int j = l; j <= r; ++j)
            v[j] = min(c, v[j]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        ans += v[i] * v[i];
    cout << ans << "\n";
    return 0;
}

