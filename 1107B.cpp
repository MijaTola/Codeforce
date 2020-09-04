#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        long long x,y;
        cin >> x >> y;
        x--;
        cout << x * 9 + y << "\n";
    }
    return 0;
}

