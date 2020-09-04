#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;
        vector<long long> v(n);

        for (long long &x: v) 
            cin >> x;

        int cnt = 0;
        int last = v[0] > 0;
        int ans = 0;
        long long mx = -1e9;
        long long mn = 1e9;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int cur = v[i] > 0;
            if(last == cur) {
                cnt++;
                mx = max(mx, v[i]);
                mn = min(mn, abs(v[i]));
            } else {
                
                if(!last) sum -= mn;
                else {
                    sum += mx;
                }
                mx = v[i];
                mn = abs(v[i]);
                ans++;
                cnt = 1;
            }
            last = cur;
        }
        ans++;
        if(last) sum += mx;
        else sum -= mn;

        //cout << ans << "\n";
        cout << sum << "\n";

        

    }
    return 0;
}

