#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int> > v(n);
        vector<int> b(n);
        set<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        
        int last = 1e9;
        bool flag = 1;
        for (auto p: v) {
            if(p.second < last or last + 1 == p.second) {
            } else flag = 0;
            last = p.second;
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}

