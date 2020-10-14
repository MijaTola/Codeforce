#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        bool flag = 0;

        for (int i = 0; i < n; ++i) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            flag |= b == c;
        }

        if(flag and (m * m) % 4 == 0) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

