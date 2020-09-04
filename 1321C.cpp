#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {

    auto ver = [] (char x, char y) {
        return x - y == 1;
    };

    cin >> n >> s;
    vector<pair<char,int> > v;

    for (int i = 0; i < n; ++i) 
        v.emplace_back(s[i], 1);

    int ans = 0;
    while(1) {
        int id = -1;
        for (char i = 'z'; i >= 'a'; i--) {
            for (int j = 0; j < (int)s.size(); ++j) {
                if(i == s[j]) {
                    if(ver(s[j], s[j - 1])) {
                        id = j;
                        goto fin;
                    }
                    if(ver(s[j], s[j + 1])) {
                        id = j;
                        goto fin;
                    }
                }
            }
        }
        fin:
        if(id == -1) break;
        string t = "";
        
        for (int i = 0; i < (int)s.size(); ++i)
            if(i != id) t += s[i];
        s = t;
        ans++;

    }
    cout << ans << "\n";

    return 0;
}

