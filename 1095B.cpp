#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    if(n == 2) {
        cout << 0 << "\n";
        return 0;
    }
    cout << min(v[n - 1] - v[1], v[n - 2] - v[0]) << "\n";
    return 0;
}

