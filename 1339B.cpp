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

        int l = n / 2;
        int r = n / 2 + 1;
        
        if(n % 2 == 0) 
            l = n / 2 - 1, r = n / 2;
        vector<int> ans;

        while(l >= 0 or r < n) {
            if(l >= 0) ans.push_back(v[l--]);
            if(r < n) ans.push_back(v[r++]);
        }

        for (auto x: ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

