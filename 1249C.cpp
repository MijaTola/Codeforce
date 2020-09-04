#include <bits/stdc++.h>

using namespace std;

long long p[40];
long long a[40];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //38
    p[0] = 1;
    
    for (int i = 1; i <= 38; ++i)
        p[i] = 3ll * p[i - 1];

    a[0] = p[0];
    for (int i = 1; i <= 38; ++i) 
        a[i] = p[i] + a[i - 1];
        
    int q;
    cin >> q;
    while(q--) {
        long long n;
        cin >> n;

        int pos = 0;
        while(a[pos] < n) pos++;

        long long ans = a[pos];
        for (int i = pos; i >= 0; i--) {
            if(ans - p[i] >= n) ans -= p[i];
        }
        
        cout << ans << "\n";
       
    }
    return 0;
}

