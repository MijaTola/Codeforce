#include <bits/stdc++.h>

using namespace std;

int t;
string s;
bool vis[200010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;


    while(t--) {
        cin >> s;
        
        int last = -1;
    
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == 'R') {
                ans = max(ans, i - last);
                last = i;
            }
        }
        ans = max(ans, (int)s.size() - last);
        cout << ans << "\n";
    }
    return 0;
}

