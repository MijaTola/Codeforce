#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        long long s,a,b,c;
        cin >> s >> a >> b >> c;
        long long cnt = s / c;
        long long prom = cnt / a;
        cnt += prom * b;
        cout << cnt << "\n";
    }
    return 0;
}

