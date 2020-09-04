#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        
        int ans = 0;
        bool first = 1;
        int cnt = 0;
        for (char x: s) {
            if(x == '0') cnt++;
            else {
                if(first) first = 0;
                else ans += cnt;
                cnt = 0;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}

