#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    
    vector<long long> v(n);

    for (auto &x: v)
        cin >> x;
    
    vector<long long> b;
    long long ans = 0;
    long long current = 0;
    for (int i = n - 1; i >= 0; i--) {
        current += v[i];
        if(i > 0) b.push_back(current);
        else ans += current;
    }
    
    sort(b.rbegin(), b.rend());

    for (int i = 0; i < k - 1; ++i)
        ans += b[i];
    
    cout << ans << "\n";

    return 0;
}

