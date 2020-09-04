#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        set<int> s,no;
        vector<int> v,cnt(n + 10,0);
        for (int i = 0; i < n + 10; ++i)
            s.insert(i);
        
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            s.erase(x);
            v.push_back(x);
            cnt[x]++;
            if(x != i) no.insert(i);
        }

        vector<int> ans;
        auto mswap = [&] (int p, int val) {
            cnt[v[p]]--;
            ans.push_back(p);
            if(!cnt[v[p]]) s.insert(v[p]);
            v[p] = val;
            cnt[val]++;
            s.erase(val);
            if(p == v[p]) no.erase(p);
        };

        for (int i = 0; i < 2 * n; ++i) {
            if(!no.size()) break;
            //ans++;
            int mex = *s.begin();
            if(mex == n) {
                int p = *no.begin();
                mswap(p, mex);
            } else {
                if(mex != v[mex]) {
                    mswap(mex, mex);
                } else break;
            }
            
        }
        
        cout << ans.size() << "\n";
        for (int x: ans)
            cout << x + 1<< " ";
        cout << "\n";
    }

    return 0;
}

