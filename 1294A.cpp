#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int v[3];
        int n;
        cin >> v[0] >> v[1] >> v[2] >> n;
        sort(v, v + 3);

        int df = v[2] - v[0];
        v[0] = v[2];
        n -= df;
        df = v[2] - v[1];
        n -= df;
        v[1] = v[2];
        if(n < 0) {
            cout << "NO\n";
            continue;
        }
        if(n % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

