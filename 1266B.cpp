#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while(t--) {
        long long x;
        cin >> x;
        if(x % 14LL > 0 and x % 14LL <= 6LL and x >= 15LL) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

