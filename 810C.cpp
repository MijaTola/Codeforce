#include <bits/stdc++.h>

using namespace std;

int n;
long long p[300010];
const int mod = 1e9 + 7;

int main(){
    p[0] = 1;

    for (int i = 1; i < 300010; ++i) 
        p[i] = (2 * p[i - 1]) % mod;

    cin >> n;
    
    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    sort(v.begin(), v.end());


    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int l = i;
        int r = (n - (i + 1));
        ans = (ans + (p[l] * v[i]) % mod) % mod;
        ans = (ans - ((p[r] * v[i]) % mod) + mod) % mod;
    }

    cout << ans << "\n";
    return 0;
}

