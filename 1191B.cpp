#include <bits/stdc++.h>

using namespace std;

int v[26][101];

int main() {
    
    memset(v, 0, sizeof v);
    for (int i = 0; i < 3; ++i) {
        string x;
        cin >> x;
        v[x[1] - 'a'][x[0] - '0']++;
    }

    
    int mx = 1e9;
    for (char x: {'m','s', 'p'}) {
        for (int i = 1; i <= 9; ++i) {
            mx = min(mx, 3 - v[x - 'a'][i]);
            int sum = (bool)v[x - 'a'][i]+ (bool)v[x - 'a'][i + 1] + (bool)v[x - 'a'][i + 2];
            mx = min(mx, 3 - sum);
        }
    }

    cout << max(mx, 0) << "\n";

    return 0;
}

