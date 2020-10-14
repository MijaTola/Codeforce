#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
    
        int n;
        cin >> n;
        
        vector<pair<int,int> > a,b;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x > 0) a.push_back({i, x});
            if(x < 0) b.push_back({i, x});
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while(a.size() and b.size()) {
            auto da = a.back();
            a.pop_back();
            auto db = b.back();
            b.pop_back();

            if(da.first < db.first) {
                int mn = min(da.second, abs(db.second));
                da.second -= mn;
                db.second += mn;
            } else {
                a.push_back(da);
                continue;
            }
            if(da.second) a.push_back(da);
            if(db.second) b.push_back(db);
        }

        long long ans = 0;
        for (auto p: a) 
            ans += p.second;
        cout << ans << "\n";
    }
    return 0;
}

