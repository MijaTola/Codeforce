#include <bits/stdc++.h>

using namespace std;

int n;
int v[10010];
int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) 
        cin >> v[i];

    int mx = 1;
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        mx = max(v[i], mx);
        if(mx == i) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

