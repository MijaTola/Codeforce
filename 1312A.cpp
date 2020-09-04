#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;
        puts(n % m == 0 ? "YES" : "NO");
    }
    return 0;
}

