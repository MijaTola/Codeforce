#include <bits/stdc++.h>

using namespace std;

int t,x,y;

int main() {
    
    auto get = [] (long long x) {
        return x * (x + 1) / 2;
    };

    cin >> t;
    while(t--) {
        cin >> x >> y;
        
        int p = 0;

        while(1) {
            long long val = get(p) + x + y;
            if(val % 2 == 0 and val / 2 >= x and val / 2 >= y) break;
            p++;
        }
        cout << p << "\n";
    }
    return 0;
}

