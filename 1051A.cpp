#include <bits/stdc++.h>

using namespace std;

int main() {

    int t; cin >> t;
    while(t--) {

        vector<int> up;
        vector<int> low;
        vector<int> num;
        string s; cin >> s;

        for (int i = 0; i < (int)s.size(); ++i) {
            if(isdigit(s[i])) num.push_back(i);
            if(s[i] >= 'a' and s[i] <= 'z')
                low.push_back(i);
            if(s[i] >= 'A' and s[i] <= 'Z')
                up.push_back(i);
        }

        if(up.size() and low.size() and num.size()) {
            cout << s << "\n";
            continue;
        }

        if(!up.size() and low.size() and num.size()) {
            if(low.size() > num.size()) s[low[0]] = 'A';
            else s[num[0]] = 'A';
            cout << s << "\n";
            continue;
        }

        if(up.size() and !low.size() and num.size()) {
            if(up.size() > num.size()) s[up[0]] = 'a';
            else s[num[0]] = 'a';
            cout << s << "\n";
            continue;
        }
        if(up.size() and low.size() and !num.size()) {
            if(up.size() > low.size()) s[up[0]] = '1';
            else s[low[0]] = '1';
            cout << s << "\n";
            continue;
        }

        if(up.size() and !low.size() and !num.size()) {
            s[up[0]] = 'a';
            s[up[1]] = '1';
            cout << s << "\n";
            continue;
        }

        if(!up.size() and !low.size() and num.size()) {
            s[num[0]] = 'a';
            s[num[1]] = 'A';
            cout << s << "\n";
            continue;
        }

        if(!up.size() and low.size() and !num.size()) {
            s[low[0]] = '1';
            s[low[1]] = 'A';
            cout << s << "\n";
            continue;
        }

    }
    return 0;
}

