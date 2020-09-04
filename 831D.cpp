#include <bits/stdc++.h>

using namespace std;

int n,k,p;
long long d[2010];

int main(){
    

    cin >> n >> k >> p;
    
    vector<int> a(n), b(k);

    for (int &x: a)
        cin >> x;

    for (int &x: b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto get = [&] (long long i, long long j) {
        return abs(i - j);
    };
    

    long long ans = 1e12;
    for (int i = 0; i <= k - n; ++i) {
        long long mx = 0;
        for (int j = 0, ini = i; j < n and ini < k; ++j, ini++) {
            mx = max(mx, get(b[ini], a[j]) + get(b[ini], p));
        }
        ans = min(ans, mx);
    }
    
    cout << ans  << "\n";

    return 0;
}
