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
        
        multiset<int> s1,s2;
        set<int> a,b;

        for (int i = 0; i < n; ++i) {
            s2.insert(v[i]);
            b.insert(v[i]);
        }
        
        vector<pair<int,int> > ans;

        for (int i = 0, l = 1, r = n - 1; i < n; ++i, l++, r--) {
            s1.insert(v[i]);
            s2.erase(s2.lower_bound(v[i]));

            a.insert(v[i]);

            if(!s2.count(v[i])) b.erase(v[i]);

            if((int)a.size() == l and *a.rbegin() == l
                    and (int)b.size() == r and *b.rbegin() == r) {
                ans.emplace_back(a.size(), b.size());
            }
        }

        cout << ans.size() << "\n";

        for (auto p: ans)
            cout << p.first << " " << p.second << "\n";
        

    }

    return 0;
}

