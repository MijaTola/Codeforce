#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<long long, long long> > v;

int main() {
    cin >> n;
    long long gcd = 0;
    for (int i = 0; i < n; ++i) {
        long long x,y;
        cin >> x >> y;
        v.push_back({x,y});
        gcd = __gcd(gcd, x * y);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur = max(__gcd(gcd, v[i].first), __gcd(gcd, v[i].second));
        gcd = cur;
    }
    if(gcd == 1) cout << "-1\n";
    else cout << gcd <<  "\n";
    return 0;
}
