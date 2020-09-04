#include <bits/stdc++.h>

using namespace std;

int n;
int v[300010];
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    
    int a = 0;
    int b = n - 1;
    

    long long ans = 0;
    while(a < b and a < n and b >= 0) {
        int s = (v[a] + v[b]) * (v[a] + v[b]);
        ans += s;
        a++;
        b--;
    }
    cout << ans << "\n";
    return 0;
}

