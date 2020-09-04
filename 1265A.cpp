#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        for (int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == '?') {
                char l = 'x';
                char r = 'z';
                if(i) l = s[i - 1];
                if(i + 1 < (int)s.size()) r = s[i + 1];

                for (char c = 'a'; c <= 'c'; c++) {
                    if(c != l and c != r) {
                        s[i] = c;
                        break;
                    }

                }
            }
        }
        bool flag = 1;
        for (int i = 0; i < (int) s.size() - 1; ++i)
            if(s[i] == s[i + 1] or s[i] == '?') flag = 0;

        if(flag) cout << s << "\n";
        else cout << "-1\n";
    }
    return 0;
}

