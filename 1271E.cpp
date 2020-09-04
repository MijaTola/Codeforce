#include <bits/stdc++.h>

using namespace std;

int val[1000];
int main() {
    
    int n,k;
    cin >> n >> k;


    for (int i = 1; i <= n; ++i) {
        int u = i;
        cout << i << ": ";
        while(u != 1) {
            cout << u << " ";
            val[u]++;
            if(u & 1) u--;
            else u >>= 1;
        }
        cout << "\n";
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if(val[i] >= k) ans = i;
        cout << i << ": " << val[i] << "\n";
    }
    cout << ans << "\n";
    return 0;
}

