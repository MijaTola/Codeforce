#include <bits/stdc++.h>

using namespace std;

int v[110];
int main() {
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x]++;
    }
    
    int ans = 0;
    
    int mx = 0;
    for (int i = 0; i < 110; ++i) 
        mx = max(mx, v[i]);
    
    int d = mx / k;
    if(mx % k != 0) d++;
    int total = d * k;
    for (int i = 0; i < 110; ++i) {
        if(!v[i]) continue;
        ans += total - v[i];
    }
    cout << ans << "\n";
    return 0;
}

