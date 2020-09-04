#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[50010];
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    for (int i = 1; i < n; ++i)
        v[i] += v[i - 1];
    
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(j - i + 1 < k) continue;
            long double x = v[j];
            if(i) x -= v[i - 1];
            ans = max(ans, x / (j - i + 1));
        }
    }
    cout.precision(10);
    cout<< fixed << ans << "\n";
    return 0;
}

