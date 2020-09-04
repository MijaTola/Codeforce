#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;

    if(x > y) {
        if(x > y + z) cout << "+\n";
        else cout << "?\n";
    } else if(y > x) {
        if(y > x + z) cout << "-\n";
        else cout << "?\n";
    } else {
        if(z == 0)cout << "0\n";
        else cout << "?\n";
    }
    return 0;
}

