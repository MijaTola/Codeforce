#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n; 
    set<string> ans;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        set<char> ss;
        for (int j = 0; j < (int)s.size(); ++j)
            ss.insert(s[j]);
        
        string y = "";
        for (char p: ss) y += p;
        ans.insert(y);
    }
    cout << ans.size() << "\n";
    return 0;
}

