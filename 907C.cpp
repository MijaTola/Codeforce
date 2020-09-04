#include <bits/stdc++.h>

using namespace std;

int guess[27];
bool vis[27];
bool vis2[27];
int main(){
    memset(guess, 0, sizeof guess);
    int n; cin >> n;
    bool found = 0;
    int ans = 0;
    while(n--) {
        char c; cin >> c;
        if(c == '.') {
            string s; cin >> s;
            if(found) continue;
            for (int i = 0; i < (int)s.size(); ++i) 
                guess[s[i] - 'a']--;
        }
        if(c == '!') {
            memset(vis2, false,sizeof vis2);
            string s; cin >> s;
            if(found) ans++;
            for (int i = 0; i < (int)s.size(); ++i) 
                vis2[s[i] - 'a'] = 1;
            for (int i = 0; i < 26; ++i)
                if(vis2[i]) guess[i]++;
        }
        if(c == '?') {
            char x; cin >> x;
            if(!vis[x - 'a'] and found) ans++;
        }
        if(found) continue;
        memset(vis, 0, sizeof vis);
        int mx = INT_MIN;
        int cur = 0;
        for (int i = 0; i < 26; ++i) mx = max(guess[i],mx);
        for (int i = 0; i < 26; ++i) if(guess[i] == mx) {vis[i] = 1; cur++; }
        //for (int i = 0; i < 26; ++i) cout << guess[i] << " "; puts("");
        if(cur == 1) found = 1;
        //cout << mx << " " << cur << " " << found << "\n";
    }
    cout << ans << "\n";
    return 0;
}

