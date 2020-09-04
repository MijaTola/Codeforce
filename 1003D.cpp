#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    map<long long ,int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    while(q--) {
        int x;
        cin >> x;
        int c = 0;
        for (long long i = 1LL << 31; i > 0 and x; i /= 2) {
            if(i > x or mp[i] == 0) continue;
            long long cur = min(x / i, (long long)mp[i]);
            c += cur;
            x -= cur * i;
        }
        if(x != 0) cout << "-1\n";
        else cout << c << "\n";
    }
    return 0;
}

