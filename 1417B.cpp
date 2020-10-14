#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int k;

    cin >> k;

    while(k--) {
    
        int n,t;
        cin >> n >> t;

        map<int,vector<int> > mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
        
        set<int> s;
        
        vector<int> ans(n, 0);

        for (auto [x, y]: mp) {
            if(s.count(x)) continue;
            s.insert(x);
            
            int dt = t - x;

            if(mp.count(dt)) {
                if(x != dt) {
                   for (int i = 0; i < (int)mp[x].size(); ++i)
                       ans[mp[x][i]] = 1;
                } else {
                    
                   for (int i = 0; i < (int)mp[x].size(); ++i)
                       if(i & 1) ans[mp[x][i]] = 1;
                }
                s.insert(dt);
            }
        }

        for (int i = 0; i < n;++i)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}

