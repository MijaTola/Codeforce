#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    auto get = [](long long x) -> long long{
        return (x * (x + 1)) / 2ll;
    };
    while(t--) {
        long long n,m;
        cin >> n >> m;
        
        if(m == 0) {
            cout << "0\n";
            continue;
        } 
        long long ans = 0;
        long long z = n - m;
        if(z >= m) {
            ans =  2 * m * m;
            long long sz = 2 * m;
            z -= m;
            long long dv = (z + 1) / 2;
            int l = dv + sz;
            int r = dv + sz - 1;
            ans += get(n) - get(l);
            ans += get(n) - get(r);
        } else {
            ans =  2ll * z * z;
            long long sz = 2ll * z;
            m -= z;
            long long range = sz + m;
            ans += get(range) - get(sz);
        }
        cout << ans << "\n";
    }
    return 0;
}

