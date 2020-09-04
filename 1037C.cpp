#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s,t;
    cin >> n >> s >> t;
    string ds = "", dt = "";
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if(s[i] == s[i + 1]) continue;
        if(t[i] == t[i + 1]) continue;
        if(s[i] == t[i]) continue;
        if(s[i + 1] == t[i + 1]) continue;
        ans++;
        swap(s[i], s[i + 1]);
    }

    for (int i = 0; i < n; ++i)
        ans += s[i] != t[i];

    cout << ans << "\n";
  
    return 0;
}


