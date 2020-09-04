#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    long long k;
    string s,t;
    cin >> n >> k >> s >> t;
    
    long long ans = 0;
    long long cur = 1;

    for (int i = 0; i < n; ++i) {
        cur *= 2;
        if(s[i] == 'b') cur--;
        if(t[i] == 'a') cur--;
        cur = max(1ll, min(k, cur));
        ans += cur;
    }
    cout << ans << "\n";
    return 0;
}

