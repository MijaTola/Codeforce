#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> s;
        
        string ans = "";

        for (int i = 0; i < n; ++i) {
            int v = s[i] - '0';
            if(v & 1 and (int)ans.size() < 2) ans += s[i];
        }
        
        if(ans.size() != 2) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}

