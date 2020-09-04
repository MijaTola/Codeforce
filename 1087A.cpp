#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int sz = s.size();

    bool flag = 1;
    if(sz & 1) flag = 0;
    int l = 0;
    int r = sz - 1;
    string ans = "";
    for (int i = 0; i < sz; ++i) {
        if(flag) ans += s[r--];
        else ans +=s[l++];
        flag = !flag;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}

