#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int r;  cin >> r;
        for (int j = 0; j < r; ++j) {
            int x; cin >> x;
            v[x]++;
        }
    }

    int mx = 0;

    for (int i = 0; i < 110; ++i) {
        mx = max(v[i],mx);
    }

    for (int i = 0; i < 110; ++i) {
        if(v[i] == mx) cout << i << " ";
    }
    cout << "\n";
    return 0;
}

