#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        bool flag = 0;
        for (int i = 0; i < n - 1; ++i) {
            if(a[i] <= a[i + 1]) flag = 1;
        }


        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

