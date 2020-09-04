#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v, v + n);
        
        int mn = min(v[n - 1], v[n - 2]);

        cout << min(mn - 1, n - 2) << "\n";
    }
    return 0;
}

