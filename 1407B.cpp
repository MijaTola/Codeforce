#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> v(n);


        for (int &x: v)
            cin >> x;

        sort(v.rbegin(), v.rend());
       
        int cur = v[0];
        set<int> vis;
        while(cur > 0) {
            int mx = -1;
            int id = -1;

            for (int j = 0; j < n; ++j) {
                if(vis.count(j)) continue;
                int gcd = __gcd(cur, v[j]);
                if(gcd > mx) {
                    mx = gcd;
                    id = j;
                } else if(gcd == mx and v[j] > v[id]) {
                    id = j;
                }
            }
                
            if(id == -1) break;
            vis.insert(id);
            cout << v[id] << " ";
            cur = mx;
        }

        for (int i = 0; i < n; ++i)
            if(!vis.count(i))
                cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}

