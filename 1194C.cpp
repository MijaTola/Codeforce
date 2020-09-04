#include <bits/stdc++.h>

using namespace std;

int a[30],b[30];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;

    while(q--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        string s,t,p;
        cin >> s >> t >> p;
        int pos = 0;
        for (int i = 0 ; i < (int)t.size(); ++i) 
            if(s[pos] == t[i]) pos++;

        if(pos != (int)s.size()) {
            cout << "NO\n";
            continue;
        }

        for (char x: s) 
            a[x - 'a']++;
        
        for (char x: p) 
            a[x - 'a']++;

        for (char x: t) 
            b[x - 'a']++;

        bool flag = 1;
        for (int i = 0; i < 27; ++i) 
            flag &= a[i] >= b[i];

        if(flag) cout << "YES\n";
        else cout << "NO\n";
        
    }
    return 0;
}

