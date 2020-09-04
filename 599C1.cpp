#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int mn[100010];
int main() {
    for (int i = 0; i < 100010; ++i)
        mn[i] = 1e9;
    
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    v[n] = 1e9;

    for (int i = n - 1; i >= 0; i--) 
        mn[i] = min(v[i], mn[i + 1]);
    

    int mx = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, v[i]);
        if(mx <= mn[i + 1]) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}

