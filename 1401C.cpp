#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n),b;
        
        for (int &x: v) {
            cin >> x;
            b.push_back(x);
        }

        sort(b.begin(), b.end());
        
        
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            if(b[i] != v[i]) 
                flag &= __gcd(v[i], b[0]) == b[0];
            
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";


    }

    return 0;
}

