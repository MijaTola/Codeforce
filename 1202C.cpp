#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        vector<int> v,h;

        for (auto c: s) {
            if(c == 'W' or c == 'S') v.push_back(c == 'W' ? 1 : - 1);
            else h.push_back(c == 'D' ? 1 : -1);
        }
        
        auto f = [] (vector<int> & v, bool check = 0) {
            vector<int> p;
            if((int)v.size() == 0) return 1;
            int pos = 0;
            p.push_back(0);
            for (auto x: v) {
                pos += x;
                p.push_back(pos);
            }
            
            if(p.size() == 0) return 1;
            int mx = p[0];
            int mn = p[0];
            mx = *max_element(p.begin(), p.end());
            mn = *min_element(p.begin(), p.end());
            
            if(!check) return mx - mn + 1;

            int ans = mx - mn + 1;

            auto premx = p;
            auto premn = p;
            auto sufmx = p;
            auto sufmn = p;

            for (int i = 1; i < (int)p.size(); ++i) {
                premx[i] = max(premx[i], premx[i - 1]);
                premn[i] = min(premn[i], premn[i - 1]);
            }

            for (int i = p.size() - 2; i >= 0; i--) {
                sufmx[i] = max(sufmx[i], sufmx[i + 1]);
                sufmn[i] = min(sufmn[i], sufmn[i + 1]);
            }

            for (int i = 0; i < (int)p.size(); ++i) {
                ans = min(ans, max(premx[i], sufmx[i] + 1) - min(premn[i], sufmn[i] + 1) + 1);
                ans = min(ans, max(premx[i], sufmx[i] - 1) - min(premn[i], sufmn[i] - 1) + 1);
            }

            return ans;
        };
        
        cout << min(1LL * f(v) * f(h, 1), 1LL * f(v, 1) * f(h)) << "\n";

    }
    return 0;
}
