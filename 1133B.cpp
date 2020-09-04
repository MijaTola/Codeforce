#include <bits/stdc++.h>

using namespace std;

int v[110];

int main() {
    int n,k;
    cin >> n >> k;
    
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        v[x % k]++;
    }
    
    int ans = (v[0] / 2) * 2;
    for (int i = 1; i <= k / 2; ++i) {
        int dif = abs(i - k);
        if(dif != i)ans += min(v[i], v[dif]) * 2;
        else ans += (v[i] / 2) * 2;
    }
    cout << ans << "\n";
    return 0;
}

