#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int,int> > v(n);
        
        set<int> s;

        for (auto &p: v)
            cin >> p.first;

        for (auto &p: v) {
            cin >> p.second;
            s.insert(p.second);
        }

        if((int)s.size() >= 2) {
            sort(v.begin(), v.end());
        }
        
        bool flag = 1;
        for (int i = 0; i < n - 1; ++i) {
            flag &= v[i].first <= v[i + 1].first;
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}

