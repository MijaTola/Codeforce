#include <bits/stdc++.h>

using namespace std;

bool a[27];
int p[27];
int main(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    string st = "";
    string t = s;
    for (int i = 0; i < (int)s.size(); ++i) 
        a[s[i] - 'a'] = 1;
    
    int pos = 0;
    for (int i = 0; i < 27; ++i) {
        if(a[i]) {
            st += (char)(i + 'a');
            p[i] = pos++;
        }
    }
    if((int)t.size() < k) {
        while((int)t.size() < k) t += st[0];
        cout <<t << "\n";
        return 0;
    }
    for (int i = k - 1; i >= 0; i--) {
        int cp = p[s[i] - 'a'];
        if(cp + 1 < (int)st.size()) {
            char l = st[cp + 1];
            t[i] = l;
            for (int j = i + 1; j < min(k,(int)t.size()); ++j)
                t[j] = st[0];
            break;
        }
    }
    for (int i = 0; i < k; ++i)
        cout << t[i];
    cout << "\n";
    return 0;
}

