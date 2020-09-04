#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
set<int> s;
bool a[100010], b[100010];
int main() {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        int l,r;
        cin >> l >> r;
        mx = max(mx, r);
        for (int j = l; j <= r; ++j) 
            v[j] = i;
    }
    ;
    int k;
    cin >> k;
    
    for (int i = k - 1; i >= 1; i--) 
        a[v[i]] = 1;
    
    for (int j = k; j <= mx; ++j) 
        b[v[j]] = 1;
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if(a[i] and !b[i]) ans++;
    }
    cout << n - ans << "\n";
    return 0;
}

