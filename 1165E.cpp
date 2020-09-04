#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n;

int main() {
    
    cin >> n;

    vector<long long> a(n), b(n), xi, ans(n);

    for (auto &x: a)
        cin >> x;

    for (auto &x: b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());


    for (int i = 0; i < n; ++i)
        xi.push_back(a[i] * b[i]);
    
    sort(xi.begin(), xi.end());
    int l = 0, r = n - 1;
    
    for (int i = 0; i < n; ++i) {
        if(i & 1) ans[r--] = xi[i];
        else ans[l++] = xi[i];
    }
    

    long long res = 0;
    
    for (int i = 0, dn = n; i < n;  ++i, dn--) 
        ans[i] *= dn;

    for (int i = n - 2; i >= 0; i--) 
        ans[i] += ans[i + 1];   

    for (int i = 0; i < n; ++i) {
        res += ans[i];
        res %= mod;
    }

    cout << res << "\n";
    return 0;
}

