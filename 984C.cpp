#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        long long a,b,c;
        cin >> a >> b >> c;
    
        auto g = __gcd(a,b);
        a/=g;
        b/=g;
        cout << b << " test\n";
        if(b % 2 == 0 or b % 5 == 0 or b == 1)
            cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}

