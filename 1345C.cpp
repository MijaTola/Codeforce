#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int &x: v)
            cin >> x;
        
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert((((i + v[i % n]) % n) + n) % n);
        }

        if((int)s.size() ==  n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

