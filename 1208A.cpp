#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> v[0] >> v[1] >> n;
        v[2] = v[1] ^ v[0];

        n %= 3;
        cout << v[n] << "\n";
    }
    return 0;
}

