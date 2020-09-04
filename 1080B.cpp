#include <bits/stdc++.h>

using namespace std;

long long even(long long x) {
    return x * (x + 1);
}

long long odd(long long x) {
    return x * x;
}

int main() {
    int q; 
    cin >> q;
    while(q--) {
        long long l, r;
        cin >> l >> r;
        long long fevenl = l / 2;
        long long fevenr = r / 2;
        long long foddl = l / 2 + (l % 2);
        long long foddr = r / 2 + (r % 2);
        if(l & 1) foddl--;
        else fevenl--;
        long long ev = even(fevenr) - even(fevenl);
        long long od = odd(foddr) - odd(foddl);
        cout << ev - od << "\n";
    }
    return 0;
}

