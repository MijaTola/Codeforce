#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        
        if(k <= sqrt(n) and n % 2 == k % 2)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

