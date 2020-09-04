#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;

        while(a-- and n and n >= 20) {
            n /= 2;
            n += 10;
        }
        
        if(b * 10 >= n) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

