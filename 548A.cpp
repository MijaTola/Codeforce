#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    int k;
    cin >> s >> k;

    auto check = [] (string x) {
        string t = x;
        reverse(t.begin(), t.end());
        return t == x;
    };
    
    if(s.size() % k != 0) return cout << "NO\n", 0;
    int dv = s.size() / k;
    bool flag = 1;
    for (int i = 0; i <= (int)s.size() - dv; i += dv) {
        flag &= check(s.substr(i, dv));
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

