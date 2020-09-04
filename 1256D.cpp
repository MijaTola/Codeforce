#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {

        int n,k;
        string s;
        cin >> n >> k >> s;

        vector<int> v;

        for (int i = 0; i < (int)s.size(); ++i) 
            if(s[i] == '0') v.push_back(i);

        int i = 0, p = 0;
        string ans = "";
        while(p < (int)s.size()) {
            if(i < (int)v.size() and abs(v[i] - p) <= k) {
                ans += "0";
                k -= abs(v[i] - p);
                i++;
            } else ans += "1";
            p++;
        }
        cout << ans << "\n";

    }
    return 0;
}

