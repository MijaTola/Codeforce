#include <bits/stdc++.h>

using namespace std;

string s,t;

int l[200010];
int r[200010];

int main() {
    cin >> s >> t;
    
    int pos = 0;
    for (int i = 0; i < (int)s.size(); ++i) 
        if(s[i] == t[pos]) l[pos] = i, pos++;
    
    pos = t.size() - 1;
    
    for (int i = s.size() - 1; i >= 0; --i) 
        if(s[i] == t[pos]) r[pos] = i, pos--;
    
    int sz = s.size() - l[t.size() - 1];
    int ans = max(sz - 1, r[0]);
    for (int i = 0; i < (int)t.size() - 1; ++i) {
        int dl = l[i];
        int dr = r[i + 1];
        ans = max(ans, dr - dl - 1);
    }
    cout << ans << "\n";
    return 0;
}

