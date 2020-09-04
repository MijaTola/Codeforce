#include <bits/stdc++.h>

using namespace std;

int t,n;
int main() {
    
    cin >> t;
    while(t--) {
        vector<pair<int,int> > v;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            v.emplace_back(x,y);
        }
        v.emplace_back(0,0);
        sort(v.begin(), v.end());

        bool flag = 1;
        for (int i = 1; i < (int)v.size(); ++i) {
            flag &= (v[i].first >= v[i - 1].first and v[i].second >= v[i - 1].second);
        }
        if(!flag) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        for (int i = 1; i < (int)v.size(); ++i) {
            for (int j = 0; j < v[i].first - v[i - 1].first; ++j)
                cout << "R";
            for (int j = 0; j < v[i].second - v[i - 1].second; ++j)
                cout << "U";

        }
        cout << "\n";
    }

    return 0;
}

