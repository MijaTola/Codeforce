#include <bits/stdc++.h>

using namespace std;

int main() {

    string s,t;
    cin >> s >> t;
    int ans = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = i; j < (int)s.size(); ++j) {
            string x = "";
            for (int k = 0; k < (int)s.size(); ++k) {
                if(k >= i and k <= j) continue;
                x += s[k];
            }
            int p = 0;
            for (int k = 0; k < (int)x.size(); ++k) 
                if(x[k] == t[p]) p++;

            if(p == (int)t.size()) {
                int sz = (j - i + 1);
                ans = max(ans, sz);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

