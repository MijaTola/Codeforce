#include <bits/stdc++.h>

using namespace std;

int l[30];
int r[30];
bool vis[30];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    noans:
    while(t--) {
        for (int i = 0; i < 30; ++i) 
            l[i] = -1, r[i] = -1, vis[i] = 0;
        
        string s;
        cin >> s;
        
        int pos = s[0] - 'a';
        int ini = pos;
        vis[pos] = 1;
        for (int i = 1; i < (int)s.size(); ++i) {
            if(!vis[s[i] - 'a']) {
                if(r[pos] == -1) {
                    r[pos] = s[i] - 'a';
                    l[s[i] - 'a'] = pos;
                } else if(l[pos] == -1) {
                    l[pos] = s[i] - 'a';
                    r[s[i] - 'a'] = pos;
                    ini = s[i] - 'a';
                } else {
                    cout << "NO\n";
                    goto noans;
                }
                vis[s[i] - 'a'] = 1;
                pos = s[i] - 'a';
            } else {
                if(r[pos] == s[i] - 'a') pos = r[pos];
                else if(l[pos] == s[i] - 'a') pos = l[pos];
                else {
                    cout << "NO\n";
                    goto noans;
                }
            }
            vis[s[i] - 'a'] = 1;
        }
        
        cout << "YES\n";
        string ans = "";

        while(ini != -1) {
            ans += (char)(ini + 'a');
            ini = r[ini];
        }

        for (int i = 0; i < 26; ++i)
            if(!vis[i]) ans += (char)(i + 'a');
        cout << ans << "\n";
    }
    return 0;
}

