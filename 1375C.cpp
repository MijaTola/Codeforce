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

        vector<int> cur;
        stack<int> last;
        last.push(-1);
        vector<pair<int,int> > mnmx;

        for (int i = 0; i < n; ++i) {
            if(cur.size() == 0 or cur.back() < v[i]) {
                cur.push_back(v[i]);
            } else {
                mnmx.emplace_back(cur[0], cur.back());
                cur.clear();
                cur.push_back(v[i]);
            }
        }
        mnmx.emplace_back(cur[0], cur.back());
        int mx = mnmx.back().second;
        int mn = mnmx[0].first;
        mnmx.pop_back();
        if(mn < mx) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

