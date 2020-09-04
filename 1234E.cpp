#include <bits/stdc++.h>

using namespace std;

int v[200010];
long long a[200010];

int main() {
    
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
        cin >> v[i];

    for (int i = 1; i < m; ++i) 
        a[i] = abs(v[i] - v[i - 1]);

    for (int i = 1; i < m; ++i)
        a[i] += a[i - 1];
    
    for (int i = 1; i < n - 1; ++i) {
        long long ans = 0;
        if(i) ans += a[i - 1];
        ans += a[m - 1] - a[i + 1];
        ans += abs(a[i - 1] - a[i + 1]);
        //cout << abs(a[i - 1] - a[i + 1]) << " carajo\n";;
        ans += abs(v[i] - v[0]);
        cout << ans << "\n";
    }
    return 0;
}

