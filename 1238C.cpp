#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    int q;
    cin >> q;
    while(q--) {
        int h,n;
        cin >> h >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        v.push_back(0);
        reverse(v.begin(), v.end());
        int ans = 0;
        
        int cur = h;
        while(cur - 2 >= 0 ) {
            int pos = lower_bound(v.begin(), v.end(), cur) - v.begin() - 1;
            if(cur - v[pos] > 1) {
                cur = v[pos] + 1;
                continue;
            }
            if(cur - 2 <= v[pos - 1]) {
                cur = v[pos - 1];
                continue;
            }
            ans++;
            cur = cur - 2;
        }
        cout << ans << "\n";
 
    }
    return 0;
}
