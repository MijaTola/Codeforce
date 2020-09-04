#include <bits/stdc++.h>
 
using namespace std;
 
int t,n;
int v[100010];
int b[100010];
 
int main() {
 
    cin >> t;
 
    while(t--) {
        cin >> n;
        
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            b[i] = v[i];
        }
        

        int mx = -1;
        int mn = 1e9;
        for (int i = 0; i < n; ++i) {
            if(v[i] == -1) continue;
            if(i and v[i - 1] == -1)
                mx = max(mx, v[i]), mn = min(mn, v[i]);
            if(i + 1 < n and v[i + 1] == -1)
                mx = max(mx, v[i]), mn = min(mn, v[i]);
        }

        int mid = (mx + mn) / 2;
        if(mx == -1) mid = 0;

        auto f = [] (int k) {
            for (int i = 0; i < n; ++i) 
                if(v[i] == -1) b[i] = k;

            int mx = 0;
            for (int i = 1; i < n; ++i) 
                mx = max(mx, abs(b[i] - b[i - 1]));
            return mx;
        };

        cout << f(mid) << " " << mid << "\n";
    }
    return 0;
}
