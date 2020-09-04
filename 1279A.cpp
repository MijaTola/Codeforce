#include <bits/stdc++.h>

using namespace std;

int v[3];
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v + 3);
        v[2] -= v[1];
        v[2] -= v[0];
        if(v[2] > 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

