#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for (int &x: a)
            cin >> x;
        
        for (int &x: b)
            cin >> x;

        if(n & 1) {
            if(a[(n ) / 2] != b[(n)/ 2]) {
                cout << "No\n";
                continue;
            }
        }
        
        vector<pair<int,int> > s,t;
        
        int l = 0, r = n -1;

        while(l < r) {
            s.emplace_back(min(a[l],a[r]), max(a[l], a[r]));
            t.emplace_back(min(b[l],b[r]), max(b[l], b[r]));
            l++, r--;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) cout << "Yes\n";
        else cout << "No\n";
        
    }
    return 0;
}

