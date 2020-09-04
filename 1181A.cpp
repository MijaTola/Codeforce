#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long x,y,z;
    cin >> x >> y >> z;

    long long ans = x / z + y / z;
    x %= z, y %= z;
    
    long long cur = (x + y) / z;
    long long id = 0;
    if(cur) {
        ans += cur;
        long long left = (x + y) % z;
        if(x < y) {
            x -= left;
            id = x;
        } else {
            y -= left;
            id = y;
        }
    }
    cout << ans << " " << id << "\n";
    return 0;
}

