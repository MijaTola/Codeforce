#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long a,b;
    cin >> a >> b;
    
    long long ans = 0;
    while(1) {
        ans += (a / b);
        a %= b;
        if(!a) break;
        if(a < b) swap(a,b);
    }
    cout << ans << "\n";
    return 0;
}

