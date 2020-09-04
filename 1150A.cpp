#include <bits/stdc++.h>

using namespace std;

int n,m,r;
int a[35], b[35];

int main() {
    cin >> n >> m >> r;
    int mn = 1e9;
    int mx = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        mn = min(mn, x);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x;
        mx = max(mx, x);
    }
    
    cout << max(r,(r / mn) * mx + r % mn)<< "\n";
    return 0;
}

