#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> v(n);

        for (int &x: v) 
            cin >> x;

        sort(v.begin(), v.end());

        long long ans = -1;
        map<long long,long long> mp,mp2;
        for (int u: v) {
            if(u % k == 0) continue;
            long long a = -1, b = 1e9;
            while(b - a > 1) {
                long long mid = (a + b) / 2;

                if(mid * k >= u) b = mid;
                else a = mid;
              
            }
            
            long long df = b * k - u;
            mp[df]++;
            if(!mp2.count(df)) mp2[df] = b * k;
        }
        

        for (auto x: mp2) {
            if(mp[x.first] <= 1) {
                ans = max(ans, x.first);
                continue;
            }
            ans = max(ans, x.first + (mp[x.first] - 1) * k);   

        }
        cout << ans + 1<< "\n";
       
    }

    return 0;
}


