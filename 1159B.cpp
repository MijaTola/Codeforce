#include <bits/stdc++.h>

using namespace std;

int n;
int v[300010];
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];


    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
        int id = i;
        int d = id;
        int mn = 0;
        if((n - 1) - id > id) {
            d = (n - 1) - id;
            mn = min(v[i], v[n - 1]);
        } else {
            d = id;
            mn = min(v[i], v[0]);
        }
        ans = min(ans, (long long)mn / d);
    }
    cout << ans << "\n";
    return 0;
}

