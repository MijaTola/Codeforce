#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    int e = 0, o = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x & 1) o++;
        else e++;
    }
    int od = 0, de = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if(x & 1) od++;
        else de++;
    }

    cout << min(od, e) + min(de, o) << "\n";
    return 0;
}

