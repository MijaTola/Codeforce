#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int c = 1e9;
    int ans = 1e9;

    for (int i = 1; i < 10100; ++i) {
        int cost = 0;
        for (int j = 0; j < n; ++j) {
            if(abs(v[j] - i) <= 1) continue;
            if(v[j] > i) {
                cost += abs(v[j] - (i + 1));
            } else {
                cost += abs((i) - (v[j] + 1));
            }
        }
        if(cost < c) {
            c = cost;
            ans = i;
        }
    }
    cout << ans << " " << c << "\n";
    return 0;
}

