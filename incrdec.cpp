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
        
        int cnt = 0;
        int last = -1;
        bool flag = 1;
        int mx = 0;
        vector<int> a,b;
        for (int i = 0; i < n; ++i) {
            if(v[i] != last) {
                cnt = 1;
            } else cnt++;
            
            if(i & 1) a.push_back(v[i]);
            else b.push_back(v[i]);
            mx = max(mx, v[i]);
            last = v[i];
            flag &= cnt <= 2;
        }
        
        int cur = 0;

        for (int i = 0; i < n; ++i)
            if(v[i] == mx) cur++;

        if(flag and cur == 1) {
            cout << "YES\n";
            for (auto x: a)
                cout << x << " ";

            for (int i = b.size() - 1; i >= 0; i--)
                cout << b[i] << " ";
            cout << "\n";
        }  else cout << "NO\n";


    }
    return 0;
}

