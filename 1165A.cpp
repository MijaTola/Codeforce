#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x,y;
    string s;
    cin >> n >> x >> y >> s;
    
    int p = s.size() - 1;
    int ans = 0;
    while(p > (n - x - 1) and p >= 0) {
        if(s[p] == '1' and p != (n - y - 1)) ans++;
        p--;
    }
    if(s[n - y - 1] == '0') ans++;
    cout << ans << "\n";

    return 0;
}

