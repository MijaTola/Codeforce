#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while(t--) {
     
        int n;
        long long k;
        cin >> n >> k;
        
        vector<int> v(n);
    
        for (int &x: v) {
            cin >> x;
        }

        
        auto check = [&]() {
            bool flag = 1;
            bool zero = 0;
            for (int i = 0; i < n; ++i) {
                flag &= v[i] >= 0;   
                zero |= v[i] == 0;
            }
            
            return !zero or !flag;
        };

        while(check() and k > 0) {
            k--;
            int mx = -1e9;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, v[i]);
            }

            for (int i = 0; i < n; ++i) {
                v[i] = mx - v[i];
            }
        }

        if(k % 2 == 0) {
            for (int i = 0; i < n; ++i)
                cout << v[i] << " ";
            cout << "\n";
        } else {
            int mx = -1e9;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, v[i]);
            }

            for (int i = 0; i < n; ++i) {
                v[i] = mx - v[i];
            }

            for (int i = 0; i < n; ++i)
                cout << v[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}

