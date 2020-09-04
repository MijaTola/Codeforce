#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        long long a,b;
        cin >> a >> b;

        if(a > b)  {
            swap(a,b);
        }

        if(a == b) {
            cout << "0\n";
            continue;
        }

        if(__builtin_popcountll(b / a) != 1 or b % a != 0) {
            cout << "-1\n";
            continue;
        }
        
        long long ans = 0;
        long long x = b / a;
        while(x % 8 == 0) ans++, x /= 8;
        while(x % 4 == 0) ans++, x /= 4;
        while(x % 2 == 0) ans++, x /= 2;
        cout << ans << "\n";

    }
    return 0;
}

