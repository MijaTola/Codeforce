#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<pair<int,int> > v[200010], fin[200010];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v[x].push_back({y,i});
        fin[y].push_back({y,i});
    }
    
    
    
    set<pair<int,int> > s;
    vector<int> ans;

    for (int i = 1; i <= 200000; ++i) {
        for (auto x: v[i])
            s.insert({-x.first, x.second});

        for (auto x: fin[i - 1]) 
            s.erase({-x.first, x.second});
        
        if((int)s.size() <= k) continue;
        

        while((int)s.size() > k) {
            auto x = s.begin();
            ans.push_back((*x).second + 1);
            s.erase(x);
        }
        
    }
    
    cout << ans.size() << "\n";

    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}

