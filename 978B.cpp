#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if(s[i] == 'x') cur++;
        else {
            if(cur >= 3) ans += (cur - 2);
            cur = 0;
        }
    }
    if(cur >= 3) ans += (cur - 2);
    cout << ans << "\n";
    return 0;
}

