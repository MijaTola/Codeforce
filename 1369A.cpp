#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int x = n / 2;
        if(x & 1 or n & 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

