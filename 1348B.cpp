#include <bits/stdc++.h>

using namespace std;

int v[110];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        
        set<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            s.insert(v[i]);
        }
        if((int)s.size() > k) {
            cout << "-1\n";
            continue;
        }
    
        vector<int> ans,cycle;

        for (int x: s)
            cycle.push_back(x);

        while((int)cycle.size() < k)
            cycle.push_back(*s.rbegin());
    
        cout << 10000 << "\n";
        while((int)ans.size() < 10010) {
            for (auto x: cycle) 
                ans.push_back(x);
        }

        for (int i = 0; i < 10000; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

