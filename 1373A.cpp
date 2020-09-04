#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        long long a,b,c;
        cin >> a >> b >> c;
        
        if(a == c and b == 1) {
            cout << "-1 -1\n";
            continue;
        }
        if(a < c) {
            cout << 1 << " ";
        } else {
            cout << "-1 " << b << "\n";;
            continue;
        }

        if(b * a < c) cout << "-1\n";
        else if(b * a > c) cout << b << "\n";
        else cout << "-1\n";
        
    }
    return 0;
}

