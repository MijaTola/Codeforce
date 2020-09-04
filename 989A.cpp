#include <bits/stdc++.h>

using namespace std;

set<char> st[110];
int main(){
    
    string s; cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '.') continue;
        if(i) st[i - 1].insert(s[i]);
        if(i + 1 < (int)s.size()) st[i + 1].insert(s[i]);
        st[i].insert(s[i]);
    }

    for (int i = 0; i < (int)s.size(); ++i) {
        if(st[i].size() == 3) return cout << "Yes\n",0;
    }
    cout << "No\n";
    return 0;
}

