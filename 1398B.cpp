#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        
        char last= '.';
        int cur = 0;
        vector<int> v;
        for (int i = 0; i < (int)s.size(); ++i) {
            if(last != s[i]) {
                if(last == '1') v.push_back(cur);
                cur = 1;
            } else cur++;

            last = s[i];
        }
        
                if(last == '1') v.push_back(cur);

        sort(v.rbegin(), v.rend());

        int ans = 0;
        for (int i = 0; i < (int)v.size(); i += 2)
            ans += v[i];

        cout << ans << "\n";
    }
    return 0;
}

