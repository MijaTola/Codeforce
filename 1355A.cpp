#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        long long n,k;
        cin >> n >> k;
        
        long long dn = n;
        int cnt = 1;
        while(cnt < k) {
            long long p = dn;
            long long mn = 10;
            long long mx = 0;
            while(dn > 0) {
                mx = max(mx, dn % 10);
                mn = min(mn, dn % 10);
                dn /= 10;
            }
            dn = p + mx * mn;
            if(mx * mn == 0) break;
            cnt++;
        }
        
        cout << dn << "\n";
    }

    return 0;
}

