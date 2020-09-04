#include <bits/stdc++.h>

using namespace std;

int c,s;
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        cin >> c >> s;
       
        long long dv = s / c;

        long long mod = s % c;
        
        long long left = c - mod;

        long long ans = left * (dv * dv) + mod * (dv + 1) * (dv + 1);
        cout << ans << "\n";

    }
    return 0;
}

