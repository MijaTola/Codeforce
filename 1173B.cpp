#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = n / 2 + 1;
    cout << ans << "\n";
    int i = 1;
    for (; i <= n / 2; ++i) 
        cout << 1 << " " << i << "\n";
    
    for (i = 1; i <= n / 2 + (n & 1); ++i) 
        cout << ans << " " << i << "\n";
    return 0;
}

