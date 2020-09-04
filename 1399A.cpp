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

        sort(v.begin(), v.end());
        
        bool flag = 1;
        for (int i = 1; i < (int)v.size(); ++i) {
            flag &= abs(v[i] - v[i - 1]) <= 1;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

