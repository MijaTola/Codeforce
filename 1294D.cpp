#include <bits/stdc++.h>

using namespace std;

long long q,x,n;
long long current[500010];
set<long long> s;


int main() {
    //ios::sync_with_stdio(false); cin.tie(0);

    cin >> q >> x;
    n = x;
    for (int i = 0; i < x; ++i) {
        current[i] = i;
        s.insert(i);
    }

    while(q--) {
        long long y;
        cin >> y;
        long long mod = y % x;
        s.erase(current[mod]);
        current[mod] += x;
        s.insert(current[mod]);
        cout << *s.begin() << "\n";
    }
    return 0;
}

