#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        long long v[3];
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v + 3);
        
        long long ans = 0;
       
        long long df = v[2] - v[1];
        long long mn = min(df, v[0]);

        ans += mn;
        v[2] -= mn;
        v[0] -= mn;
        long long dv = v[0] / 2;
        if(v[2] > dv) {
            ans += dv;
            v[2] -= dv;
        } 
        
        if(v[1] > dv) {
            ans += dv;
            v[1] -= dv;
        }
        mn = min(v[1], v[2]);
        ans += mn;
        v[1] -= mn;
        v[2] -= mn;
        if((v[1] or v[2]) and v[0] & 1) ans++;
        cout << ans << "\n";
    }
    return 0;
}

