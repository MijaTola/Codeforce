#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int p = 2;
    long long ans = 0;
    while(p < n) {
        ans += (p * (p + 1));
        p++;
    }
    cout << ans << "\n";
    return 0;
}

