#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    if(m % n != 0) return cout << "-1\n",0;
    
    int d = m / n;
    int ans = 0;
    while(d != 1) {
        if(ans > m) return cout << "-1\n",0;
        if(d % 3 == 0) d /= 3;
        else if(d % 2 == 0) d /= 2;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}

